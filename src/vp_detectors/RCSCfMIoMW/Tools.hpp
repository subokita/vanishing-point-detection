#include <opencv2/core/core.hpp>

namespace vanishing_point {

cv::Point2f lineSegmentCenterPoint(cv::Vec4f line_segment);

double distancePoint2Line(cv::Point3f line, cv::Point2f point);

double errorLineSegmentPoint2VP(  cv::Vec4f line_segment,
                                  cv::Point3f homogeneos_vp,
                                  cv::Point2f *center_point = 0,
                                  cv::Point2f *end_point = 0,
                                  cv::Point3f *line_center_vp = 0);

// to apply this method, principal point is setted as (0,0)
std::vector<cv::Point2f> estimationVPby4LinesCase1(
                                          std::vector<cv::Point3f> lines,
                                          double *focal_length = 0);


// to apply this method, principal point is setted as (0,0)
std::vector<cv::Point2f> estimationVPby4LinesCase2(
                                          std::vector<cv::Point3f> lines,
                                          double *focal_length = 0);

std::vector< std::vector<cv::Point2f> > estimationVPby4LinesInAll9Cases(
                                  std::vector<cv::Point3f> lines,
                                  std::vector<double> *vector_focal_length = 0);

bool isPointLaySegmentLine(cv::Point2f point,
                           cv::Vec4f segment_points);

std::vector< std::vector<cv::Point2f> > filterHypotheses(
                            std::vector< std::vector<cv::Point2f> > vps,
                            std::vector< double > &focos,
                            std::vector< cv::Vec4f > segments,
                            float threshold = 0.001);
}
