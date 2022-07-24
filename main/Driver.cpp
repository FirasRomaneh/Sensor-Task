#include "local.h"
#include "Lidar.hpp"
#include "Image.hpp"
#include "IMU.hpp"
#include "GPS.hpp"

int main()
{
    std::string path;
    std::cout << "************************Welcome*******************" << std::endl;
    std::cout << "Enter The Path of Folder: ";
    std::cin >> path;
    Image image(path);
    Lidar lidar(path);
    GPS gps(path);
    IMU imu(path);
    image.ReadFromFile();
    lidar.ReadFromFile();
    gps.ReadFromFile();
    imu.ReadFromFile();
    std::vector<Sensor *> sensor;
    sensor.push_back(new Image(path));
    sensor.push_back(new Lidar(path));
    sensor.push_back(new GPS(path));
    sensor.push_back(new IMU(path));
    int input;
    do
    {
        std::cout << "*************************************************" << std::endl;
        std::cout << "The menu:-" << std::endl;
        std::cout << "1- LDR Sensor\n2- Image Sensor\n3- GPS Sensor\n4- IMU Sensor\n5- All Sensor\n6- Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> input;
        switch (input)
        {
        case 1:
            std::cout << "**************************************" << std::endl;
            std::cout << "The Average Data Of LIDAR is: " << lidar.Average() << std::endl;
            std::cout << "The Max Data Of LIDAR is: " << lidar.Max() << std::endl;
            std::cout << "The Min Data Of LIDAR is: " << lidar.Min() << std::endl;
            std::cout << "**************************************" << std::endl;
            break;
        case 2:
            std::cout << "**************************************" << std::endl;
            std::cout << "The Average Data Of Image is: " << image.Average() << std::endl;
            std::cout << "The Max Data Of Image is: " << image.Max() << std::endl;
            std::cout << "The Min Data Of Image is: " << image.Min() << std::endl;
            std::cout << "**************************************" << std::endl;
            break;
        case 3:
            std::cout << "**************************************" << std::endl;
            std::cout << "The Average Data Of GPS is: " << gps.Average() << std::endl;
            std::cout << "The Max Data Of GPS is: " << gps.Max() << std::endl;
            std::cout << "The Min Data Of GPS is: " << gps.Min() << std::endl;
            std::cout << "**************************************" << std::endl;
            break;
        case 4:
            std::cout << "**************************************" << std::endl;
            std::cout << "The Average Data Of IMU is: " << imu.Average() << std::endl;
            std::cout << "The Max Data Of IMU is: " << imu.Max() << std::endl;
            std::cout << "The Min Data Of IMU is: " << imu.Min() << std::endl;
            std::cout << "**************************************" << std::endl;
            break;
        case 5:
            std::cout << "**************************************" << std::endl;
            std::cout << "The Average Data Of LIDAR is: " << lidar.Average() << std::endl;
            std::cout << "The Max Data Of LIDAR is: " << lidar.Max() << std::endl;
            std::cout << "The Min Data Of LIDAR is: " << lidar.Min() << std::endl;
            std::cout << "**************************************" << std::endl;
            std::cout << "**************************************" << std::endl;
            std::cout << "The Average Data Of Image is: " << image.Average() << std::endl;
            std::cout << "The Max Data Of Image is: " << image.Max() << std::endl;
            std::cout << "The Min Data Of Image is: " << image.Min() << std::endl;
            std::cout << "**************************************" << std::endl;
            std::cout << "**************************************" << std::endl;
            std::cout << "The Average Data Of GPS is: " << gps.Average() << std::endl;
            std::cout << "The Max Data Of GPS is: " << gps.Max() << std::endl;
            std::cout << "The Min Data Of GPS is: " << gps.Min() << std::endl;
            std::cout << "**************************************" << std::endl;
            std::cout << "**************************************" << std::endl;
            std::cout << "The Average Data Of IMU is: " << imu.Average() << std::endl;
            std::cout << "The Max Data Of IMU is: " << imu.Max() << std::endl;
            std::cout << "The Min Data Of IMU is: " << imu.Min() << std::endl;
            std::cout << "**************************************" << std::endl;
            break;
        case 6:
            std::cout << "**************************************" << std::endl;
            std::cout << "Good Bye -_- -_-" << std::endl;
            break;
        default:
            std::cout << "**************************************" << std::endl;
            std::cout << "Error in The Input" << std::endl;
            break;
        }
    } while (input != 6);
}