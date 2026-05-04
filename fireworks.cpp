#include <opencv2/opencv.hpp>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace cv;
using namespace std;

// 粒子结构体
struct Particle {
    Point2f pos;
    Point2f vel;
    Point2f acc;
    int lifetime;
    Scalar color;
};

// 烟花爆炸类
class Firework {
public:
    vector<Particle> particles;
    int lifetime;
    
    Firework(Point2f startPos) : lifetime(0) {
        // 创建粒子
        for (int i = 0; i < 100; i++) {
            Particle p;
            p.pos = startPos;
            
            // 随机方向和速度
            float angle = (rand() % 360) * CV_PI / 180.0f;
            float speed = 2.0f + (rand() % 50) / 10.0f;
            p.vel.x = speed * cos(angle);
            p.vel.y = speed * sin(angle);
            p.acc = Point2f(0, 0.1f); // 重力加速度
            p.lifetime = 100 + rand() % 100;
            
            // 随机颜色
            int colorType = rand() % 3;
            if (colorType == 0) {
                p.color = Scalar(0, 255, 255); // 黄色
            } else if (colorType == 1) {
                p.color = Scalar(255, 0, 255); // 紫色
            } else {
                p.color = Scalar(255, 255, 0); // 青色
            }
            
            particles.push_back(p);
        }
    }
    
    void update() {
        for (auto& p : particles) {
            p.vel += p.acc;
            p.pos += p.vel;
            p.lifetime--;
        }
        lifetime++;
    }
    
    bool isAlive() {
        return !particles.empty();
    }
    
    void draw(Mat& frame) {
        for (auto& p : particles) {
            if (p.lifetime > 0) {
                // 根据生命周期改变透明度效果
                int alpha = (p.lifetime * 255) / 150;
                circle(frame, Point(p.pos.x, p.pos.y), 2, p.color, -1);
            }
        }
        // 移除已死亡的粒子
        particles.erase(
            remove_if(particles.begin(), particles.end(),
                      [](const Particle& p) { return p.lifetime <= 0; }),
            particles.end()
        );
    }
};

int main() {
    srand((unsigned)time(0));
    
    // 创建窗口和视频写入器
    int width = 800;
    int height = 600;
    string windowName = "Fireworks Display";
    namedWindow(windowName, WINDOW_NORMAL);
    
    // 创建黑色背景帧
    Mat frame = Mat::zeros(height, width, CV_8UC3);
    
    vector<Firework> fireworks;
    int frameCount = 0;
    
    while (true) {
        // 清空背景（添加运动模糊效果）
        frame = frame * 0.95;
        
        // 随机创建新烟花
        if (frameCount % 30 == 0) {
            int x = 100 + rand() % (width - 200);
            int y = 100 + rand() % (height - 200);
            fireworks.push_back(Firework(Point2f(x, y)));
        }
        
        // 更新和绘制烟花
        for (auto& fw : fireworks) {
            fw.update();
            fw.draw(frame);
        }
        
        // 移除已完成的烟花
        fireworks.erase(
            remove_if(fireworks.begin(), fireworks.end(),
                      [](const Firework& fw) { return !fw.isAlive(); }),
            fireworks.end()
        );
        
        // 显示帧
        imshow(windowName, frame);
        
        // 按 ESC 键退出
        int key = waitKey(30);
        if (key == 27) break;
        
        frameCount++;
    }
    
    destroyAllWindows();
    return 0;
}