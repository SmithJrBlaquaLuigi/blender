// Copyright (c) 2016 libmv authors.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// Author: Tianwei Shen <shentianweipku@gmail.com>
// This file contains functions to do camera resection.

#ifndef LIBMV_AUTOTRACK_RESECT_H
#define LIBMV_AUTOTRACK_RESECT_H

#include "libmv/base/vector.h"
#include "libmv/autotrack/tracks.h"
#include "libmv/autotrack/reconstruction.h"

namespace mv {

/*!
    Estimate the Euclidean pose of a camera from 2D to 3D correspondences.

    This takes a set of markers visible in one frame (which is the one to
    resection), such that the markers are also reconstructed in 3D in the
    reconstruction object, and solves for the pose and orientation of the
    camera for that frame.

    \a markers should contain \l Marker markers \endlink belonging to tracks
    visible in the one frame to be resectioned. Each of the tracks associated
    with the markers must have a corresponding reconstructed 3D position in the
    \a *reconstruction object.

    \a *reconstruction should contain the 3D points associated with the tracks
    for the markers present in \a markers.

    \note This assumes a calibrated reconstruction, e.g. the markers are
          already corrected for camera intrinsics and radial distortion.
    \note This assumes an outlier-free set of markers.

    \return True if the resection was successful, false otherwise.

    \sa EuclideanIntersect, EuclideanReconstructTwoFrames
*/
bool EuclideanResect(const vector<Marker> &markers,
                     Reconstruction *reconstruction, bool final_pass, int intrinsics);

}  // namespace mv

#endif  // LIBMV_AUTOTRACK_RESECT_H
