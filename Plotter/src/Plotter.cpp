#include "Plotter/Plotter.h"
#include "qwt_plot.h"
#include "qwt_plot_curve.h"
#include "qwt_plot_grid.h"
#include <QApplication>
#include <QPolygonF>

using namespace ELCT350::Plotter;
using namespace std;

#pragma region Plotter
#pragma region Constructors and Destructors
Plotter::Plotter(const string& title)
       : _plot(make_unique<QwtPlot>()), _grid(make_unique<QwtPlotGrid>())
{
  _plot->setTitle(title.c_str());
  _grid->attach(_plot.get());
  _plot->resize(1024, 768);
}

Plotter::~Plotter()
{
}
#pragma endregion

#pragma region Observers
void Plotter::show() const
{
  for (const auto& curve : _dataSeries)
  {
    curve.second->show();
  }
  _plot->show();
}
#pragma endregion

#pragma region Operators
Plotter::DataSeries& Plotter::operator<<(const string& title)
{
  auto existing = _dataSeries.find(title);
  if (existing == _dataSeries.end())
  {
    _dataSeries[title] = unique_ptr<DataSeries>(new DataSeries(title));
    auto& series = _dataSeries[title];
    series->_curve->attach(_plot.get());
    return *_dataSeries[title];
  }

  return *existing->second;
}
#pragma endregion
#pragma endregion

#pragma region DataSeries
#pragma region Constructors
Plotter::DataSeries::DataSeries(const string& name)
       : _curve(make_unique<QwtPlotCurve>(name.c_str())),
         _data(make_unique<QPolygonF>())
{
}
#pragma endregion

#pragma region Observers
void Plotter::DataSeries::show() const
{
  _curve->setSamples(*_data);
}
#pragma endregion

#pragma region Operators
Plotter::DataSeries& Plotter::DataSeries::operator<<(const Point& point)
{
  *_data << QPointF(get<0>(point), get<1>(point));
  return *this;
}
#pragma endregion
#pragma endregion