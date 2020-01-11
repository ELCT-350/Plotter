#pragma once
#include "Plotter/PlotterExports.h"
#include <map>
#include <memory>
#include <string>
#include <QApplication>

class QwtPlot;
class QwtPlotCurve;
class QwtPlotGrid;
class QPolygonF;

namespace ELCT350
{
  namespace Plotter
  {
    #pragma region Types
    typedef std::tuple<double, double> Point;
    #pragma endregion

    class Plotter final
    {
    public:
      #pragma region Types
      class DataSeries
      {
      public:
        #pragma region Operators
        PLOTTER_EXPORT DataSeries& operator<<(const Point& point);
        #pragma endregion
      private:
        #pragma region Variables
        mutable std::unique_ptr<QwtPlotCurve> _curve;
        std::unique_ptr<QPolygonF> _data;
        #pragma endregion

        #pragma region Constructors
        DataSeries(const std::string& name);
        #pragma endregion

        #pragma region Observers
        void show() const;
        #pragma endregion

        friend Plotter;
      };
      #pragma region

      #pragma region Constructors
      PLOTTER_EXPORT Plotter(const std::string& title);
      PLOTTER_EXPORT ~Plotter();
      #pragma endregion

      #pragma region Observers
      PLOTTER_EXPORT void show() const;
      #pragma endregion

      #pragma region Operators
      PLOTTER_EXPORT DataSeries& operator<<(const std::string& dataSeries);
      #pragma endregion
    private:
      #pragma region Variables;
      std::unique_ptr<QwtPlot> _plot;
      std::unique_ptr<QwtPlotGrid> _grid;
      std::map<std::string, std::unique_ptr<DataSeries> > _dataSeries;
      #pragma endregion
    };
  }
}