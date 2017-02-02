#include <string>
#include <tuple>

#include "gnuplot-iostream.h"


void line(const std::vector< std::tuple<float, float> > &data,
        std::string title="", std::string xLabel="", std::string yLabel="");
void points(const std::vector< std::tuple<float, float> > &data,
        std::string title="", std::string xLabel="", std::string yLabel="");

int main(int argc, char *argv[]) {
    std::vector< std::tuple<float, float> > data;
    data.push_back(std::make_tuple(0,0));
    data.push_back(std::make_tuple(1,1));

    line(data);
    points(data);

    return 0;
}


void line(const std::vector< std::tuple<float, float> > &data,
        std::string title, std::string xLabel, std::string yLabel) {
    Gnuplot gp;

    gp << "set title '" + title + "'\n";
    gp << "set xlabel '" + xLabel + "'\n";
    gp << "set ylabel '" + yLabel + "'\n";

    gp << "unset key\n";

    std::string markerForStdinInput = "'-'";
    gp << "plot " + markerForStdinInput + " ";
    gp << "with linespoints ";
    gp << "linetype 1 ";
    gp << "linewidth 2 ";
    gp << "linecolor rgb '#0060ad' ";
    gp << "pointtype 7 ";
    gp << "pointsize 0.5 ";
    gp << "\n";

    gp.send1d(data);
}

void points(const std::vector< std::tuple<float, float> > &data,
        std::string title, std::string xLabel, std::string yLabel) {
    Gnuplot gp;

    gp << "set title '" + title + "'\n";
    gp << "set xlabel '" + xLabel + "'\n";
    gp << "set ylabel '" + yLabel + "'\n";

    gp << "unset key\n";
    gp << "set grid\n";
    gp << "set size ratio -1\n";

    std::string markerForStdinInput = "'-'";
    gp << "plot " + markerForStdinInput + " ";
    gp << "linecolor rgb 'red' ";
    gp << "pointtype 7 ";
    gp << "pointsize 0.5 ";
    gp << "\n";

    gp.send1d(data);
}

