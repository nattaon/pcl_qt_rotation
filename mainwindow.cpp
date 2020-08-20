#include "mainwindow.h"
#include "build/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect ui to function
    connect(ui->bt_load, SIGNAL(clicked()), this, SLOT(ButtonLoadPressed()));
    connect(ui->bt_save, SIGNAL(clicked()), this, SLOT(ButtonSavePressed()));
    connect(ui->bt_filter, SIGNAL(clicked()), this, SLOT(ButtonFilterPressed()));
    //connect(ui->bt_alignaxis, SIGNAL(clicked()), this, SLOT(ButtonAlignAxisPressed()));
    //connect(ui->bt_caldist, SIGNAL(clicked()), this, SLOT(ButtonCalcDistancePressed()));
    connect(ui->bt_resetcam, SIGNAL(clicked()), this, SLOT(ButtonResetCameraPressed()));

    //connect(ui->bt_setazimuth, SIGNAL(clicked()), this, SLOT(ButtonSetAzimuthPressed()));
    //connect(ui->bt_setelev, SIGNAL(clicked()), this, SLOT(ButtonSetElevationPressed()));

    connect(ui->bt_viewup, SIGNAL(clicked()), this, SLOT(ButtonViewUpPressed()));
    connect(ui->bt_viewdown, SIGNAL(clicked()), this, SLOT(ButtonViewDownPressed()));
    connect(ui->bt_viewleft, SIGNAL(clicked()), this, SLOT(ButtonViewLeftPressed()));
    connect(ui->bt_viewright, SIGNAL(clicked()), this, SLOT(ButtonViewRightPressed()));


    connect(ui->bt_alignmajor, SIGNAL(clicked()), this, SLOT(ButtonAlignAxisMajorPressed()));
    connect(ui->bt_alignmiddle, SIGNAL(clicked()), this, SLOT(ButtonAlignAxisMiddlePressed()));
    connect(ui->bt_alignminor, SIGNAL(clicked()), this, SLOT(ButtonAlignAxisMinorPressed()));

    connect(ui->bt_pca, SIGNAL(clicked()), this, SLOT(ButtonPCAPressed()));
    connect(ui->bt_boundingbox, SIGNAL(clicked()), this, SLOT(ButtonBoundingBoxPressed()));

    connect(ui->bt_xrot, SIGNAL(clicked()), this, SLOT(ButtonXrotPressed()));
    connect(ui->bt_yrot, SIGNAL(clicked()), this, SLOT(ButtonYrotPressed()));
    connect(ui->bt_zrot, SIGNAL(clicked()), this, SLOT(ButtonZrotPressed()));

    //pointcloud
    pointcloud.reset(new PointCloudXYZRGB);
    cloud_downsample_for_pca.reset(new PointCloudXYZ);

    //pcl viewer
    viewer_input.reset(new pcl::visualization::PCLVisualizer("pointcloud input"));
    viewer_input->setPosition(50,0);//window position
    viewer_input->setBackgroundColor(0, 0, 0);
    viewer_input->initCameraParameters();
    viewer_input->addCoordinateSystem();
    viewer_input->getRenderWindow()->GetRenderers()->GetFirstRenderer()->GetActiveCamera()->SetParallelProjection(1);
    //viewer_input->setRepresentationToSurfaceForAllActors();

    viewer_filtered.reset(new pcl::visualization::PCLVisualizer("pointcloud filtered"));
    viewer_filtered->setPosition(50,400);//window position
    viewer_filtered->setBackgroundColor(0, 0, 0);
    viewer_filtered->initCameraParameters();
    viewer_filtered->addCoordinateSystem();
    viewer_filtered->getRenderWindow()->GetRenderers()->GetFirstRenderer()->GetActiveCamera()->SetParallelProjection(1);

    timerId = startTimer(100); //call timerEvent every 100 msec
    time.start();

    viewer_input->registerMouseCallback( &MainWindow::mouse_callback_viewer_input, *this );
    viewer_filtered->registerMouseCallback( &MainWindow::mouse_callback_viewer_filtered, *this );

    InitPointCloud();
    //*viewer_selecting = *viewer_input;
}



void MainWindow::InitPointCloud()
{
    QString filename = "/home/okuboali/qtproject/seminar.ply";
    ui->in_filename->setText( filename );

    loadPLY(filename, pointcloud); // load to "pointcloud"


    FilterVoxelSize(pointcloud,0.01);
    ui->label_filteredpointsize->setText(QString::number(pointcloud->size()));

    //show original pointcloud in voxel =0.01
    viewer_input->addPointCloud(pointcloud, "cloud_filtered 0.01");

    //down sample point cloud, calculate PCA, draw marker on viewer_input
    pcl::copyPointCloud(*pointcloud, *cloud_downsample_for_pca);
    FilterVoxelXYZSize(cloud_downsample_for_pca,0.1); // 0.1 = 10cm

    CalculatePCA(cloud_downsample_for_pca,viewer_input);
    viewer_filtered->addPointCloud(cloud_downsample_for_pca, "cloud_downsample_for_pca");
}
void MainWindow::mouse_callback_viewer_input( const pcl::visualization::MouseEvent& event, void* )
{
    if( event.getType() == pcl::visualization::MouseEvent::MouseButtonPress && event.getButton() == pcl::visualization::MouseEvent::LeftButton ){
        std::cout << "viewer 0 Mouse : " << event.getX() << ", " << event.getY() << std::endl;
        viewer_selecting = 0;
    }
}

void MainWindow::mouse_callback_viewer_filtered( const pcl::visualization::MouseEvent& event, void* )
{
    if( event.getType() == pcl::visualization::MouseEvent::MouseButtonPress && event.getButton() == pcl::visualization::MouseEvent::LeftButton ){
        std::cout << "viewer 1 Mouse : " << event.getX() << ", " << event.getY() << std::endl;
        viewer_selecting = 1;
    }

}

boost::shared_ptr<pcl::visualization::PCLVisualizer> MainWindow::getActiveViewer(int id)
{
    if(id==0) return viewer_input;
    else return viewer_filtered;

}
void MainWindow::loadPLY(QString filename, PointCloudXYZRGB::Ptr cloud)
{
    if (filename.isEmpty ())
      return;

    //cloud.reset(new PointCloudXYZRGB); //should not be resetted, otherwise nothing be shown.
    int return_status = pcl::io::loadPLYFile (filename.toStdString (), *cloud);
    if (return_status != 0)
      {
        PCL_ERROR("Error reading point cloud %s\n", filename.toStdString ().c_str ());
        return;
      }
    ui->label_w->setText(QString::number(cloud->width));
    ui->label_h->setText(QString::number(cloud->height));
}

void MainWindow::ButtonSavePressed()
{
    // You might want to change "/home/" if you're not on an *nix platform
    QString filename = QFileDialog::getSaveFileName(this, tr ("Open point cloud"), "/home/", tr ("Point cloud data (*.pcd *.ply)"));

    PCL_INFO("File chosen: %s\n", filename.toStdString ().c_str ());

    if (filename.isEmpty ())
      return;

    int return_status;

    if (filename.endsWith (".ply", Qt::CaseInsensitive))
      return_status = pcl::io::savePLYFileBinary (filename.toStdString (), *pointcloud);
    else
    {
      filename.append(".ply");
      return_status = pcl::io::savePLYFileBinary (filename.toStdString (), *pointcloud);
    }

    if (return_status != 0)
    {
      PCL_ERROR("Error writing point cloud %s\n", filename.toStdString ().c_str ());
      return;
    }
}
void MainWindow::ButtonLoadPressed() // to viewer input
{
    QString filename =
            QFileDialog::getOpenFileName (this,
                                          tr ("Open point cloud"),
                                          "/home/",
                                          tr ("Point cloud data (*.ply)"));
    ui->in_filename->setText( filename );

    loadPLY(filename, pointcloud);


    viewer_input->removeAllPointClouds();
    viewer_input->initCameraParameters();
    viewer_input->addPointCloud(pointcloud, "pointcloud");

    if(ui->checkBox_voxel->isChecked())
    {
        ButtonFilterPressed();
    }

}
void MainWindow::ButtonResetCameraPressed()
{
    getActiveViewer(viewer_selecting)->initCameraParameters();
    //if(viewer_selecting==0) viewer_input->initCameraParameters();
    //else viewer_filtered->initCameraParameters();
}


void MainWindow::ButtonViewUpPressed()
{
    //vtkSmartPointer<vtkCamera> cam = viewer_selecting->getRenderWindow()->GetRenderers()->GetFirstRenderer()->GetActiveCamera();
    //if(viewer_selecting==0) camera = viewer_input->getRenderWindow()->GetRenderers()->GetFirstRenderer()->GetActiveCamera();
    //else camera = viewer_filtered->getRenderWindow()->GetRenderers()->GetFirstRenderer()->GetActiveCamera();
    camera = getActiveViewer(viewer_selecting)->getRenderWindow()->GetRenderers()->GetFirstRenderer()->GetActiveCamera();
    camera->Elevation(90.0);
}
void MainWindow::ButtonViewDownPressed()
{
    //vtkSmartPointer<vtkCamera> cam = viewer_selecting->getRenderWindow()->GetRenderers()->GetFirstRenderer()->GetActiveCamera();
    camera = getActiveViewer(viewer_selecting)->getRenderWindow()->GetRenderers()->GetFirstRenderer()->GetActiveCamera();
    camera->Elevation(-90.0);
}

void MainWindow::ButtonViewRightPressed()
{
    //vtkSmartPointer<vtkCamera> cam = viewer_selecting->getRenderWindow()->GetRenderers()->GetFirstRenderer()->GetActiveCamera();
    camera = getActiveViewer(viewer_selecting)->getRenderWindow()->GetRenderers()->GetFirstRenderer()->GetActiveCamera();
    camera->Azimuth(90.0);
}
void MainWindow::ButtonViewLeftPressed()
{
    //vtkSmartPointer<vtkCamera> cam = viewer_selecting->getRenderWindow()->GetRenderers()->GetFirstRenderer()->GetActiveCamera();
    camera = getActiveViewer(viewer_selecting)->getRenderWindow()->GetRenderers()->GetFirstRenderer()->GetActiveCamera();
    camera->Azimuth(-90.0);
}


void MainWindow::timerEvent(QTimerEvent *event)
{
    viewer_input->spinOnce(100);
    viewer_filtered->spinOnce(100);
}


void MainWindow::ButtonFilterPressed()  // to viewer input
{     
    double voxelsize = ui->in_filter->text().toDouble();
    FilterVoxelSize(pointcloud, voxelsize);

    //return pointcloud
    if (pointcloud->size() != 0)
    {
        viewer_input->removeAllPointClouds();
        viewer_input->addPointCloud(pointcloud, "cloud_filtered");
        ui->label_filteredpointsize->setText(QString::number(pointcloud->size()));
    }
    else
    {
        cout << "after filter pointcloud->size()==0" <<endl;
    }

}
void MainWindow::FilterVoxelSize(PointCloudXYZRGB::Ptr cloud, double size) //for input pointcloud
{
    pcl::VoxelGrid<PointTypeXYZRGB> grid;
    //set scope and pointcloud for filter
    grid.setLeafSize(size, size, size);
    grid.setInputCloud(cloud);

    //do filter(save output in new pointcloud)
    PointCloudXYZRGB::Ptr cloud_filtered(new PointCloudXYZRGB);
    grid.filter(*cloud_filtered);

    cout << "fiter voxel XYZRGB= " << size << ", size before: " << cloud->size() << ", size after: " << cloud_filtered->size() << endl;
    if (cloud_filtered->size() != 0)
    {
        pcl::copyPointCloud(*cloud_filtered, *cloud);
    }
}
void MainWindow::FilterVoxelXYZSize(PointCloudXYZ::Ptr cloud, double size) // for calculate PCA
{
    pcl::VoxelGrid<PointTypeXYZ> grid;
    //set scope and pointcloud for filter
    grid.setLeafSize(size, size, size);
    grid.setInputCloud(cloud);

    //do filter(save output in new pointcloud)
    PointCloudXYZ::Ptr cloud_filtered(new PointCloudXYZ);
    grid.filter(*cloud_filtered);

    cout << "fiter voxel XYZ= " << size << ", size before: " << cloud->size() << ", size after: " << cloud_filtered->size() << endl;
    if (cloud_filtered->size() != 0)
    {
        pcl::copyPointCloud(*cloud_filtered, *cloud);
    }
}

void MainWindow::ButtonPCAPressed()
{
    //calculate PCA, and draw a marker on the viewer_filtered
    CalculatePCA(cloud_downsample_for_pca,viewer_filtered);
}
void MainWindow::CalculatePCA(PointCloudXYZ::Ptr cloud, boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer)
{

    pcl::MomentOfInertiaEstimation <pcl::PointXYZ> feature_extractor;
    feature_extractor.setInputCloud(cloud);
    feature_extractor.compute();
    feature_extractor.getMassCenter(mass_center);
    feature_extractor.getEigenVectors(major_vector, middle_vector, minor_vector);
    feature_extractor.getOBB(min_point_OBB, max_point_OBB, position_OBB, rotational_matrix_OBB);

    mass_center_point.x = mass_center[0];
    mass_center_point.y = mass_center[1];
    mass_center_point.z = mass_center[2];

    pcl::getMinMax3D(*cloud, min3d_point, max3d_point);

    ui->label_major0->setText(QString::number(major_vector[0]));
    ui->label_major1->setText(QString::number(major_vector[1]));
    ui->label_major2->setText(QString::number(major_vector[2]));

    ui->label_middle0->setText(QString::number(middle_vector[0]));
    ui->label_middle1->setText(QString::number(middle_vector[1]));
    ui->label_middle2->setText(QString::number(middle_vector[2]));

    ui->label_minor0->setText(QString::number(minor_vector[0]));
    ui->label_minor1->setText(QString::number(minor_vector[1]));
    ui->label_minor2->setText(QString::number(minor_vector[2]));

    //PrintTransformationData();

    viewer->removeAllShapes();

    r=1.0;g=0.0;b=1.0;//purple
    viewer->addSphere(mass_center_point, 0.1, r, g, b, "mass center");

    r=1.0;g=1.0;b=0.0;//yellow
    viewer->addSphere(min3d_point, 0.1, r, g, b, "min3d point");

    r=0.0;g=1.0;b=1.0;//cyan
    viewer->addSphere(max3d_point, 0.1, r, g, b, "max3d point");


    double vector_scale = 1.0f;
    pcl::PointXYZ majorvectorfromcenter(
        major_vector[0]*vector_scale+mass_center[0],
        major_vector[1]*vector_scale+mass_center[1],
        major_vector[2]*vector_scale+mass_center[2]);
    //cout << "majorvectorfromcenter is \n" << majorvectorfromcenter << endl;
    r=1.0;g=0.0;b=0.0;//red
    viewer->addLine(mass_center_point, majorvectorfromcenter, r, g, b, "major_axis");

    pcl::PointXYZ middlevectorfromcenter(
        middle_vector[0]*vector_scale+mass_center[0],
        middle_vector[1]*vector_scale+mass_center[1],
        middle_vector[2]*vector_scale+mass_center[2]);
    //cout << "middlevectorfromcenter is \n" << middlevectorfromcenter << endl;
    r=0.0;g=1.0;b=0.0;//green
    viewer->addLine(mass_center_point, middlevectorfromcenter, r, g, b, "middle_axis");

    pcl::PointXYZ minorvectorfromcenter(
        minor_vector[0]*vector_scale+mass_center[0],
        minor_vector[1]*vector_scale+mass_center[1],
        minor_vector[2]*vector_scale+mass_center[2]);
    //cout << "minorvectorfromcenter is \n" << minorvectorfromcenter << endl;
    r=0.0;g=0.0;b=1.0;//blue
    viewer->addLine(mass_center_point, minorvectorfromcenter, r, g, b, "minor_axis");

}

void MainWindow::RotatePointCloudAlignAxis(PointCloudXYZ::Ptr cloud,
    Eigen::Matrix<float, 1, 3>  floor_plane_normal_vector,
    Eigen::Matrix<float, 1, 3>  target_plane_normal_vector)
{
    PointCloudXYZRGB::Ptr rotatedCloud(new PointCloudXYZRGB);

    Eigen::Affine3f transform = Eigen::Affine3f::Identity();
    //transform_angle.rotate(Eigen::AngleAxisf((angle)*M_PI / 180, axis));

    //Calculate the rotation angle.
    //Angle between the planes is equal to angle between the normals.
    //From the definition of the dot product,
    //we can extract the angle between two normal vectors.
    //In case of XY plane, it is equal to theta=acos(C/sqrt(A^2+B^2+C^2)
    //where A, B, C are first three coefficients of floor_plane.

    Eigen::Matrix<float, 1, 3>  rotation_vector;

    //vector/axis to rotate around
    rotation_vector = floor_plane_normal_vector.cross(target_plane_normal_vector);
    //rotation_vector = target_plane_normal_vector.cross(floor_plane_normal_vector);
    //Error	3	error C2338: THIS_METHOD_IS_ONLY_FOR_VECTORS_OF_A_SPECIFIC_SIZE
//c:\program files\pcl172qt\eigen-3.7.2\eigen\src\Geometry\OrthoMethods.h	28	1	bpp_projectv3

    cout << "Rotation Vector(perpendicular): " << rotation_vector << std::endl;

        /*
        angle between 2 planes is EQUAL
        to the acute angle of normal vector of 2 planes

        equation : n1 dot n2 = length(n1)*length(n2)*cos(angle)

        */
    float theta = acos(floor_plane_normal_vector.dot(target_plane_normal_vector) / sqrt(pow(floor_plane_normal_vector[0], 2) + pow(floor_plane_normal_vector[1], 2) + pow(floor_plane_normal_vector[2], 2)));

    transform.rotate(Eigen::AngleAxisf(theta, rotation_vector));

    cout << "theta=" << theta << " rad" << endl;
    cout << "theta=" << theta*180/M_PI << " deg" << endl;

    pcl::transformPointCloud(*cloud, *cloud, transform);


}
void MainWindow::PrintTransformationData()
{
    cout << "mass_center is \n" << mass_center << endl;
    cout << "major_vector is \n" << major_vector << endl;
    cout << "middle_vector is \n" << middle_vector << endl;
    cout << "minor_vector is \n" << minor_vector << endl;
    cout << "min_point_OBB is \n" << min_point_OBB << endl;
    cout << "max_point_OBB is \n" << max_point_OBB << endl;
    cout << "position_OBB is \n" << position_OBB << endl;
    cout << "rotational_matrix_OBB is \n" << rotational_matrix_OBB << endl;
    cout << "min3d_point is \n" << min3d_point << endl;
    cout << "max3d_point is \n" << max3d_point << endl;
}
void MainWindow::ButtonAlignAxisMajorPressed()
{
    //PointCloudXYZ::Ptr cloud_downsample(new PointCloudXYZ);
    //pcl::copyPointCloud(*pointcloud, *cloud_downsample);
    //FilterVoxelXYZSize(cloud_downsample,0.05); // 0.05 = 5cm

    //CalculatePCA(cloud_downsample,viewer_input);

/////////////////////////

    Eigen::Matrix<float, 1, 3>  floor_plane_normal_vector, target_plane_normal_vector;
    floor_plane_normal_vector[0] = major_vector(0);
    floor_plane_normal_vector[1] = major_vector(1);
    floor_plane_normal_vector[2] = major_vector(2);


    if (floor_plane_normal_vector[0]>0.9)
    {
        target_plane_normal_vector[0] = 1.0;
        target_plane_normal_vector[1] = 0.0;
        target_plane_normal_vector[2] = 0.0;
    }
    else if (floor_plane_normal_vector[0]<-0.9)
    {
        target_plane_normal_vector[0] = -1.0;
        target_plane_normal_vector[1] = 0.0;
        target_plane_normal_vector[2] = 0.0;
    }
    else if (floor_plane_normal_vector[2]>0.9)
    {
        target_plane_normal_vector[0] = 0.0;
        target_plane_normal_vector[1] = 0.0;
        target_plane_normal_vector[2] = 1.0;
    }
    else if (floor_plane_normal_vector[2]<-0.9)
    {
        target_plane_normal_vector[0] = 0.0;
        target_plane_normal_vector[1] = 0.0;
        target_plane_normal_vector[2] = -1.0;
    }
    else
    {
        cout << endl << "ERROR ROTATE!!!" << endl;

    }
    cout << "floor_plane_normal_vector is \n" << floor_plane_normal_vector << endl;
    cout << "target_plane_normal_vector is \n" << target_plane_normal_vector << endl;
    RotatePointCloudAlignAxis(cloud_downsample_for_pca,
            floor_plane_normal_vector, target_plane_normal_vector);

    viewer_filtered->removeAllPointClouds();
    //viewer_filtered->initCameraParameters();
    viewer_filtered->addPointCloud(cloud_downsample_for_pca, "rotated pointcloud");

    //CalculatePCA(cloud_downsample_for_pca,viewer_filtered);
}
void MainWindow::ButtonAlignAxisMiddlePressed()
{

}
void MainWindow::ButtonAlignAxisMinorPressed()
{

}
void MainWindow::ButtonBoundingBoxPressed()
{
    Eigen::Vector3f position(position_OBB.x, position_OBB.y, position_OBB.z);
    Eigen::Quaternionf quat(rotational_matrix_OBB);

    cout << "ButtonBoundingBoxPressed "<< position << endl;

    double bb_xsize = max_point_OBB.x - min_point_OBB.x;
    double bb_ysize = max_point_OBB.y - min_point_OBB.y;
    double bb_zsize = max_point_OBB.z - min_point_OBB.z;
    ui->label_bb_xsize->setText(QString::number(bb_xsize));
    ui->label_bb_ysize->setText(QString::number(bb_ysize));
    ui->label_bb_zsize->setText(QString::number(bb_zsize));

    getActiveViewer(viewer_selecting)->removeShape("bounding box");
    getActiveViewer(viewer_selecting)->addCube(position, quat,
        max_point_OBB.x - min_point_OBB.x,
        max_point_OBB.y - min_point_OBB.y,
        max_point_OBB.z - min_point_OBB.z, "bounding box");
    //getActiveViewer(viewer_selecting)->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_COLOR, 1.0, 1.0, 0.0, "bounding box"); //cannotset on polygonmesh
    getActiveViewer(viewer_selecting)->setRepresentationToWireframeForAllActors(); // apply wireframe for all geometry
    //Viewer.setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_REPRESENTATION, pcl::visualization::PCL_VISUALIZER_REPRESENTATION_WIREFRAME, "AABB");

    getActiveViewer(viewer_selecting)->spinOnce();

}

void MainWindow::ButtonXrotPressed()
{
    double rotate_x = ui->in_x_rot->text().toDouble();
    Eigen::Matrix<float, 1, 3>  rotation_vector;
    rotation_vector[0] = 1.0;
    rotation_vector[1] = 0.0;
    rotation_vector[2] = 0.0;

    ApplyRotationAndUpdatePointCloud(rotate_x,rotation_vector);

}
void MainWindow::ButtonYrotPressed()
{
    double rotate_y = ui->in_y_rot->text().toDouble();
    Eigen::Matrix<float, 1, 3>  rotation_vector;
    rotation_vector[0] = 0.0;
    rotation_vector[1] = 1.0;
    rotation_vector[2] = 0.0;

    ApplyRotationAndUpdatePointCloud(rotate_y,rotation_vector);
}
void MainWindow::ButtonZrotPressed()
{
    double rotate_z = ui->in_z_rot->text().toDouble();
    Eigen::Matrix<float, 1, 3>  rotation_vector;
    rotation_vector[0] = 0.0;
    rotation_vector[1] = 0.0;
    rotation_vector[2] = 1.0;

    ApplyRotationAndUpdatePointCloud(rotate_z,rotation_vector);
}

void MainWindow::ApplyRotationAndUpdatePointCloud(double rotate_angle, Eigen::Matrix<float, 1, 3>  rotation_vector)
{
    Eigen::Affine3f transform = Eigen::Affine3f::Identity();
    transform.rotate(Eigen::AngleAxisf(rotate_angle*M_PI/180, rotation_vector));
    pcl::transformPointCloud(*cloud_downsample_for_pca, *cloud_downsample_for_pca, transform);

    viewer_filtered->removeAllPointClouds();
    viewer_filtered->addPointCloud(cloud_downsample_for_pca, "rotated pointcloud");
    viewer_filtered->spinOnce();
}
void MainWindow::DrawXYZAxis()
{
    pcl::PointXYZ center(0, 0, 0);
    pcl::PointXYZ x_axis(1, 0, 0);
    pcl::PointXYZ y_axis(0, 1, 0);
    pcl::PointXYZ z_axis(0, 0, 1);
    //embeded_view->addLine(center, x_axis, 1.0f, 0.0f, 0.0f, "x_axis");
    //embeded_view->addLine(center, y_axis, 0.0f, 1.0f, 0.0f, "y_axis");
    //embeded_view->addLine(center, z_axis, 0.0f, 0.0f, 1.0f, "z_axis");

    //ui_widget_viewer->update();
}

MainWindow::~MainWindow()
{
    killTimer(timerId);
    delete ui;
}
