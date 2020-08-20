#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTime>

#include <iostream>
#include <vector>
#include <ctime>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/ply_io.h>

#include <pcl/common/common_headers.h>
#include <pcl/common/common.h>
#include <pcl/common/io.h>
#include <pcl/common/transforms.h>

#include <pcl/console/parse.h>
#include <pcl/correspondence.h>

#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/features/moment_of_inertia_estimation.h>

#include <vtkRenderWindow.h>
#include <vtkRendererCollection.h>
#include <vtkCamera.h>

typedef pcl::PointXYZ PointTypeXYZ;
typedef pcl::PointXYZRGB PointTypeXYZRGB;
typedef pcl::PointCloud<PointTypeXYZRGB> PointCloudXYZRGB;
typedef pcl::PointCloud<pcl::PointXYZ> PointCloudXYZ;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer_input;
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer_filtered;
    //boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer_selecting;
    int viewer_selecting=0;
    vtkSmartPointer<vtkCamera> camera;
    //vtkSmartPointer<vtkCamera> cam_input;
    //vtkSmartPointer<vtkCamera> cam_filtered;

    PointCloudXYZRGB::Ptr pointcloud;
    PointCloudXYZ::Ptr cloud_downsample_for_pca;
    QTime time;
    int timerId;
    double r,g,b;

    Eigen::Matrix3f plane_coefficients_matrix;
    Eigen::Vector3f mass_center;
    Eigen::Vector3f major_vector, middle_vector, minor_vector;

    pcl::PointXYZ min_point_OBB;
    pcl::PointXYZ max_point_OBB;
    pcl::PointXYZ position_OBB;

    Eigen::Matrix3f rotational_matrix_OBB;

    pcl::PointXYZ mass_center_point;
    pcl::PointXYZ min3d_point;
    pcl::PointXYZ max3d_point;


    void timerEvent(QTimerEvent *event);
    //void calculateDistance();
    //PointCloudXYZRGB::Ptr cloud loadPLY(QString filename);
    void loadPLY(QString filename, PointCloudXYZRGB::Ptr cloud);
    //void savePLY();
    void FilterVoxelSize(PointCloudXYZRGB::Ptr cloud, double size);
    void FilterVoxelXYZSize(PointCloudXYZ::Ptr cloud, double size);
    void PrintTransformationData();
    void RotatePointCloudAlignAxis(PointCloudXYZ::Ptr cloud,
        Eigen::Matrix<float, 1, 3>  floor_plane_normal_vector,
        Eigen::Matrix<float, 1, 3>  target_plane_normal_vector);
    void ZoomViewer(double value);

    void mouse_callback_viewer_input( const pcl::visualization::MouseEvent& event, void* );
    void mouse_callback_viewer_filtered( const pcl::visualization::MouseEvent& event, void* );
    void DrawXYZAxis();
    void InitPointCloud();
    void CalculatePCA(PointCloudXYZ::Ptr cloud, boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer);
    boost::shared_ptr<pcl::visualization::PCLVisualizer> getActiveViewer(int id);
    void ApplyRotationAndUpdatePointCloud(double rotate_angle, Eigen::Matrix<float, 1, 3>  rotation_vector);

private slots:
    void ButtonLoadPressed();
    void ButtonSavePressed();
    void ButtonFilterPressed();

    //void ButtonCalcDistancePressed();
    void ButtonResetCameraPressed();
    //void ButtonSetAzimuthPressed();
    //void ButtonSetElevationPressed();
    void ButtonViewUpPressed();
    void ButtonViewDownPressed();
    //void ButtonViewFrontPressed();
    //void ButtonViewBackPressed();
    void ButtonViewRightPressed();
    void ButtonViewLeftPressed();
    //void ButtonZoomPressed();
    void ButtonAlignAxisMajorPressed();
    void ButtonAlignAxisMiddlePressed();
    void ButtonAlignAxisMinorPressed();

    void ButtonPCAPressed();
    void ButtonBoundingBoxPressed();

    void ButtonXrotPressed();
    void ButtonYrotPressed();
    void ButtonZrotPressed();

};

#endif // MAINWINDOW_H
