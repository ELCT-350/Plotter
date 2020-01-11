#include "Plotter/Plotter.h"

using namespace ELCT350::Plotter;
enum ErrorCodes
{
  OK = 0
};

int main(int argc, char* argv[])
{
  QApplication gui(argc, argv);
  Plotter plot("test");
  plot << "Line" << Point(0.0, 0.0) << Point(1.0, 1.0) << Point(2.0, 4.0);
  plot.show();
  return gui.exec();
}