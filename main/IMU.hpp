#include "local.h"

class IMU: public Sensor{
    public:
      IMU(std::string path): Sensor(path){ 
      }
      void ReadFromFile() override{
        std::string FileName = Path + "/IMU.txt";
        std::ifstream ReadFile(FileName);
        std::string Read;
        while (std::getline(ReadFile, Read)){
            std::vector<std::string> tempone;
            std::stringstream tempString(Read);
            std::string temp;
            while (std::getline(tempString, temp, ',')){
                tempone.push_back(temp);
            }
            std::tuple<std::time_t, double, double, double> saveData;
            saveData = std::make_tuple(std::stod(tempone.at(0)), std::stod(tempone.at(1)), std::stod(tempone.at(2)), std::stod(tempone.at(3)));
            DataOfIMU.push_back(saveData);
        }
        ReadFile.close();
      }
      std::string Average() override{
        if (DataOfIMU.size() > 0){
          double sum1 = 0;
          double sum2 = 0;
          double sum3 = 0;
          for (auto i : DataOfIMU){
            sum1 += std::get<1>(i);
            sum2 += std::get<2>(i);
            sum3 += std::get<3>(i);
            }
            double Avg1 = sum1 / DataOfIMU.size();
            double Avg2 = sum2 / DataOfIMU.size();
            double Avg3 = sum3 / DataOfIMU.size();
            std::string Avg = "(" + std::to_string(Avg1) + ", " + std::to_string(Avg2) + ", " + std::to_string(Avg3) + ")";
            return Avg;
        }else{
          return "No Data OF IMU";
        }
      }
      std::string Min() override {
        if (DataOfIMU.size() > 0){
          double min1 = std::get<1>(DataOfIMU.at(0));
          double min2 = std::get<2>(DataOfIMU.at(0));
          double min3 = std::get<3>(DataOfIMU.at(0));
          for (auto i : DataOfIMU){
            if (min1 > std::get<1>(i)){
              min1 = std::get<1>(i);
            }
            if (min2 > std::get<2>(i)){
              min2 = std::get<2>(i);
            }
            if (min3 > std::get<3>(i)){
              min3 = std::get<3>(i);
            }
          }
          std::string min = "(" + std::to_string(min1) + ", " + std::to_string(min2) + ", " + std::to_string(min3) + ")";
          return min;
        }else{
          return "No Data OF IMU";
        }
      }
      std::string Max() override{
         if (DataOfIMU.size() > 0){
          double max1 = std::get<1>(DataOfIMU.at(0));
          double max2 = std::get<2>(DataOfIMU.at(0));
          double max3 = std::get<3>(DataOfIMU.at(0));
          for (auto i : DataOfIMU){
            if (max1 < std::get<1>(i)){
              max1 = std::get<1>(i);
            }
            if (max2 < std::get<2>(i)){
              max2 = std::get<2>(i);
            }
            if (max3 < std::get<3>(i)){
              max3 = std::get<3>(i);
            }
          }
          std::string max = "(" + std::to_string(max1) + ", " + std::to_string(max2) + ", " + std::to_string(max3) + ")";
          return max;
        }else{
          return "No Data OF IMU";
        }
      }
      void setDataOfIMU(std::vector<std::tuple<std::time_t, double, double, double>> Data){
        DataOfIMU = Data;
      }
      std::vector<std::tuple<std::time_t, double, double, double>> getDataOfIMU(){
        return DataOfIMU;
      }
    private:
       std::vector<std::tuple<std::time_t, double, double, double>> DataOfIMU;
};