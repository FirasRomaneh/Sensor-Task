#include "local.h"

class GPS : public Sensor
{
public:
  GPS(std::string path) : Sensor(path)
  {
  }
  void ReadFromFile() override
  {
    std::string FileName = Path + "/GPS.txt";
    std::ifstream ReadFile(FileName);
    std::string Read;
    while (std::getline(ReadFile, Read))
    {
      std::vector<std::string> tempone;
      std::stringstream tempString(Read);
      std::string temp;
      while (std::getline(tempString, temp, ','))
      {
        tempone.push_back(temp);
      }
      std::tuple<std::time_t, double, double> saveData;
      saveData = std::make_tuple(std::stod(tempone.at(0)), std::stod(tempone.at(1)), std::stod(tempone.at(2)));
      DataOfGPS.push_back(saveData);
    }
    ReadFile.close();
  }
  std::string Average() override
  {
    if (DataOfGPS.size() > 0)
    {
      double sum1 = 0;
      double sum2 = 0;
      for (auto i : DataOfGPS)
      {
        sum1 += std::get<1>(i);
        sum2 += std::get<2>(i);
      }
      double Avg1 = sum1 / DataOfGPS.size();
      double Avg2 = sum2 / DataOfGPS.size();
      std::string Avg = "(" + std::to_string(Avg1) + ", " + std::to_string(Avg2) + ")";
      return Avg;
    }
    else
    {
      return "No Data OF GPS";
    }
  }
  std::string Min() override
  {
    if (DataOfGPS.size() > 0)
    {
      double min1 = std::get<1>(DataOfGPS.at(0));
      double min2 = std::get<2>(DataOfGPS.at(0));
      for (auto i : DataOfGPS)
      {
        if (min1 > std::get<1>(i))
        {
          min1 = std::get<1>(i);
        }
        if (min2 > std::get<2>(i))
        {
          min2 = std::get<2>(i);
        }
      }
      std::string min = "(" + std::to_string(min1) + ", " + std::to_string(min2) + ")";
      return min;
    }
    else
    {
      return "No Data OF GPS";
    }
  }
  std::string Max() override
  {
    if (DataOfGPS.size() > 0)
    {
      double max1 = std::get<1>(DataOfGPS.at(0));
      double max2 = std::get<2>(DataOfGPS.at(0));
      for (auto i : DataOfGPS)
      {
        if (max1 < std::get<1>(i))
        {
          max1 = std::get<1>(i);
        }
        if (max2 < std::get<2>(i))
        {
          max2 = std::get<2>(i);
        }
      }
      std::string max = "(" + std::to_string(max1) + ", " + std::to_string(max2) + ")";
      return max;
    }
    else
    {
      return "No Data OF GPS";
    }
  }
  void setDataOfGPS(std::vector<std::tuple<std::time_t, double, double>> Data)
  {
    DataOfGPS = Data;
  }
  std::vector<std::tuple<std::time_t, double, double>> getDataOfGPS()
  {
    return DataOfGPS;
  }

private:
  std::vector<std::tuple<std::time_t, double, double>> DataOfGPS;
};