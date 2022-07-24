#include "local.h"

class Lidar: public Sensor{
    public:
      Lidar(std::string path) : Sensor(path){
      } 
      void ReadFromFile() override{
        std::string FileName = Path + "/LIDAR.txt";
        std::ifstream ReadFile(FileName);
        std::string Read;
        while (std::getline(ReadFile, Read)){
          std::vector<std::string> tempone;
          std::stringstream tempString(Read);
          std::string temp;
          while (std::getline(tempString, temp, ',')){
            tempone.push_back(temp);
          }
          std::stringstream TempTs(tempone.front());
          TempTs >> Timestamp;
          tempone.erase(tempone.begin());
          for (auto i : tempone){
              DataOfLidar.push_back(std::stod(i));
          }
        }
        ReadFile.close();       
      } 
      std::string Average() override{
        if(DataOfLidar.size() > 0){
          double sum = 0;
          for(auto i: DataOfLidar){
              sum += i;
          }
          double Avg = sum/(DataOfLidar.size());
          std::string Avgresult = std::to_string(Avg);
          return Avgresult;
        } else{
            return "No Data OF LIDAR";
        }
      }
      std::string Min() override{
        if(DataOfLidar.size() > 0){
          double min = DataOfLidar.front();
          for(auto i: DataOfLidar){
              if(min > i){
                  min = i;
              }
          }
          std::string Minresult = std::to_string(min);
          return Minresult;
        } else{
            return "No Data OF LIDAR";
        }
      }
      std::string Max() override{
        if(DataOfLidar.size() > 0){
          double max = DataOfLidar.front();
          for(auto i: DataOfLidar){
              if(max < i){
                  max = i;
              }
          }
          std::string Maxresult = std::to_string(max);
          return Maxresult;
        } else{
          return "No Data OF LIDAR";
        }
      }
      std::time_t getTimestamp(){
        return Timestamp;
      }
      void setDataOfLidar(std::vector<double> Data){
        DataOfLidar = Data;
      }
      std::vector<double> getDataOfLidar(){
        return DataOfLidar;
      }
    private:
      std::time_t Timestamp;
      std::vector<double> DataOfLidar;
};