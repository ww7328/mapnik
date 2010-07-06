/*****************************************************************************
 * 
 * This file is part of Mapnik (c++ mapping toolkit)
 *
 * Copyright (C) 2006 Artem Pavlenko
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *****************************************************************************/
//$Id$

#ifndef RASTER_SYMBOLIZER_HPP
#define RASTER_SYMBOLIZER_HPP

// mapnik
#include <mapnik/config.hpp>
#include <mapnik/raster_colorizer.hpp>
#include <mapnik/symbolizer.hpp>

// boost
#include <boost/shared_ptr.hpp>

namespace mapnik
{
struct MAPNIK_DECL raster_symbolizer : public symbolizer_base {
    explicit raster_symbolizer()
        : mode_("normal"),
        scaling_("fast"),
        opacity_(1.0),
        colorizer_() {}

    raster_symbolizer(const raster_symbolizer &rs)
        : mode_(rs.get_mode()),
        scaling_(rs.get_scaling()),
        opacity_(rs.get_opacity()),
        colorizer_(rs.colorizer_) {}

    std::string const& get_mode() const
    {
        return mode_;
    }
    void set_mode(std::string const& mode)
    {
        mode_ = mode;
    }
    std::string const& get_scaling() const
    {
        return scaling_;
    }
    void set_scaling(std::string const& scaling)
    {
        scaling_ = scaling;
    }
    void set_opacity(float opacity)
    {
        opacity_ = opacity;
    }
    float get_opacity() const
    {
        return opacity_;
    }
    raster_colorizer_ptr get_colorizer() const
    {
        return colorizer_;
    }
    void set_colorizer(raster_colorizer_ptr const& colorizer)
    {
        colorizer_ = colorizer;
    }
private:
    std::string mode_;
    std::string scaling_;
    float opacity_;
    raster_colorizer_ptr colorizer_;
};
}

#endif //RASTER_SYMBOLIZER_HPP
