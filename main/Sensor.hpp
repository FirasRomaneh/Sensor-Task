#ifndef SENSOR_H
#define SENSOR_H

#include "local.h"

class Sensor
{
public:
  Sensor(std::string path)
  {
    Path = path;
  }
  virtual void ReadFromFile() = 0;
  virtual std::string Average() = 0;
  virtual std::string Min() = 0;
  virtual std::string Max() = 0;

protected:
  std::string Path;
};

#endif