#include "opencv2/opencv.hpp"
int main(int argc, char *argv[]) {
    int width = 1920;
    int height = 1080;
    int fps = 30;
    cv::VideoCapture cap(0);
    cap.set(cv::CAP_PROP_FRAME_WIDTH, width);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, height);
    cap.set(cv::CAP_PROP_FPS, fps);
    cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('Y', 'U', 'Y', '2'));
    if (!cap.isOpened()) {
        return -1;
    }
    cv::Mat frame;
    //保存视频
    cv::VideoWriter writer;
    writer.open("test.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, cv::Size(width, height));
    while (true) {
        //开始时间
        auto start = static_cast<double>(cv::getTickCount());
        cap >> frame;
        if (frame.empty()) {
            break;
        }
        writer << frame;
        cv::imshow("frame", frame);
        //结束时间
        double time = ((double)cv::getTickCount() - start) / cv::getTickFrequency();
        //延时
        int delay = 1000 / fps - time * 1000;
        if (delay > 0) {
            cv::waitKey(delay);
        }
        if (cv::waitKey(1) == 27) {
            break;
        }
    }
    cap.release();
    writer.release();
    cv::destroyAllWindows();
    return 0;
}
