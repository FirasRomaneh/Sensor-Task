#include "local.h"

class Image: public Sensor{
    public:
      Image(std::string path) : Sensor(path){
      }
      void ReadFromFile() override{
        std::string FileName = Path + "/Image.txt";
        std::ifstream ReadFile(FileName);
        std::string Read;
        while (std::getline(ReadFile, Read)){
            std::vector<std::string> tempone;
            std::stringstream tempString(Read);
            std::string temp;
            while (std::getline(tempString, temp, ',')){
                tempone.push_back(temp);
            }
            if (tempone.size() == 1){
                std::stringstream TempTs(tempone.front());
                TempTs >> Timestamp;
            }
            else{
                std::vector<int> saveData;
                for (auto i : tempone){
                  saveData.push_back(std::stod(i));
                }
                DataOfImage.push_back(saveData);
            }
        }
        ReadFile.close();       
      } 
      std::string Average() override{
        if(DataOfImage.size() > 0){
            int sum = 0;
            for(auto i: DataOfImage){
                for (auto j: i){
                    sum += j;
                }
            }
            int count = DataOfImage.size() * DataOfImage.size();
            double Avg = sum/count;
            std::string AvgRes = std::to_string(Avg);
            return AvgRes;
        } else{
            return "No Data OF Image";
        }
      }
      std::string Min() override{
        if(DataOfImage.size() > 0){
            int Min = DataOfImage.front().front();
            for(auto i: DataOfImage){
                for (auto j: i){
                    if(Min > j){
                        Min = j;
                    }
                }
            }
            std::string MinRes = std::to_string(Min);
            return MinRes;
        } else{
            return "No Data OF Image";
        }
      }
      std::string Max() override{
        if(DataOfImage.size() > 0){
            int Max = DataOfImage.front().front();
            for(auto i: DataOfImage){
                for (auto j: i){
                    if(Max < j){
                        Max = j;
                    }
                }
            }
            std::string MaxRes = std::to_string(Max);
            return MaxRes;
        } else{
            return "No Data OF Image";
        }
      }
      std::time_t getTimestamp(){
        return Timestamp;
      }
      void setDataOfImage(std::vector<std::vector<int>> Data){
        DataOfImage = Data;
      }
      std::vector<std::vector<int>> getDataOfImage(){
        return DataOfImage;
      }
    private:
      std::time_t Timestamp;
      std::vector<std::vector<int>> DataOfImage;
};
