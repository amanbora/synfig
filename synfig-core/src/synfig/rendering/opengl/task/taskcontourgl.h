/* === S Y N F I G ========================================================= */
/*!	\file synfig/rendering/opengl/task/taskcontourgl.h
**	\brief TaskContourGL Header
**
**	$Id$
**
**	\legal
**	......... ... 2015 Ivan Mahonin
**
**	This package is free software; you can redistribute it and/or
**	modify it under the terms of the GNU General Public License as
**	published by the Free Software Foundation; either version 2 of
**	the License, or (at your option) any later version.
**
**	This package is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
**	General Public License for more details.
**	\endlegal
*/
/* ========================================================================= */

/* === S T A R T =========================================================== */

#ifndef __SYNFIG_RENDERING_TASKCONTOURGL_H
#define __SYNFIG_RENDERING_TASKCONTOURGL_H

/* === H E A D E R S ======================================================= */

#include "taskgl.h"
#include "../../primitive/contour.h"

/* === M A C R O S ========================================================= */

/* === T Y P E D E F S ===================================================== */

/* === C L A S S E S & S T R U C T S ======================================= */

namespace synfig
{
namespace rendering
{

class TaskContourGL: public TaskGL
{
public:
	typedef etl::handle<TaskContourGL> Handle;

public:
	Color color;
	Contour::Handle contour;

	Task::Handle clone() const { return clone_pointer(this); }

	static void render_polygon(
		const std::vector<Vector> &polygon,
		const Rect &bounds,
		bool invert,
		bool antialias,
		Contour::WindingStyle winding_style,
		const Color &color );

	static void render_contour(
		const Contour &contour,
		const Matrix &transform_matrix,
		bool invert,
		bool antialias,
		Contour::WindingStyle winding_style,
		const Color &color );

	virtual bool run(RunParams &params) const;
};

} /* end namespace rendering */
} /* end namespace synfig */

/* -- E N D ----------------------------------------------------------------- */

#endif