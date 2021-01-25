#pragma once

#include "Math.hpp"
#include "Utils.hpp"

#include <map>
#include <memory>
#include <string>
#include <vector>

namespace odr
{
struct Lane;
struct RoadMark;

const double ROADMARK_WEIGHT_STANDARD_WIDTH = 0.12;
const double ROADMARK_WEIGHT_BOLD_WIDTH = 0.25;

struct RoadMark
{
    struct RoadMarksLine
    {
        RoadMarksLine() = default;

        double width = -1;
        double length = 0;
        double space = 0;
        double tOffset = 0;
        double sOffset = 0;

        std::string name;
        std::string rule;
    };

    RoadMark() = default;

    double width = -1;
    double height = 0;
    double sOffset = 0;

    std::string type;
    std::string weight;
    std::string color;
    std::string material;
    std::string laneChange;

    std::map<double, RoadMarksLine> s_to_roadmarks_line;
};

struct RoadMarkLines
{
    RoadMarkLines() = default;
    std::vector<Mesh3D> generate_meshes() const;

    int lane_id = 0;

    double width = -1;
    double length = 0;
    double space = 0;
    double height = 0;

    std::string name;
    std::string rule;
    std::string type;
    std::string weight;
    std::string color;
    std::string material;
    std::string laneChange;

    std::vector<Line3D> lines;
};

} // namespace odr