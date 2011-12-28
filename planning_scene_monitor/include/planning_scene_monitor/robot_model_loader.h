/*********************************************************************
* Software License Agreement (BSD License)
*
*  Copyright (c) 2011, Willow Garage, Inc.
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*   * Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*   * Redistributions in binary form must reproduce the above
*     copyright notice, this list of conditions and the following
*     disclaimer in the documentation and/or other materials provided
*     with the distribution.
*   * Neither the name of the Willow Garage nor the names of its
*     contributors may be used to endorse or promote products derived
*     from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
*  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
*  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
*  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
*  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
*  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*********************************************************************/

/* Author: Ioan Sucan */

#ifndef PLANNING_SCENE_MONITOR_ROBOT_MODEL_LOADER_
#define PLANNING_SCENE_MONITOR_ROBOT_MODEL_LOADER_

#include <ros/ros.h>
#include <urdf/model.h>
#include <srdf/model.h>
#include <boost/shared_ptr.hpp>

namespace planning_scene_monitor
{
    /** @class RobotModelLoader
     *  @brief Default constructor
     *  @param robot_description The string name corresponding to the ROS param where the URDF is loaded*/
    class RobotModelLoader
    {
    public:
        /** @brief Default constructor
         *  @param robot_description The string name corresponding to the ROS param where the URDF is loaded*/
        RobotModelLoader(const std::string &robot_description);

        /** @brief Get the robot description (URDF in string format)*/
        const std::string& getRobotDescription(void) const
        {
            return robot_description_;
        }

        /** @brief Get the parsed URDF model*/
        const boost::shared_ptr<urdf::Model>& getURDF(void) const
        {
            return urdf_;
        }

        /** @brief Get the parsed SRDF model*/
        const boost::shared_ptr<srdf::Model>& getSRDF(void) const
        {
            return srdf_;
        }

    private:

        ros::NodeHandle                nh_;
        std::string                    robot_description_;
        boost::shared_ptr<srdf::Model> srdf_;
        boost::shared_ptr<urdf::Model> urdf_;

        bool loadRobotFromParamServer(void);

    };

}
#endif
