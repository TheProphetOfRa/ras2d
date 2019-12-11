//
//  Director.cpp
//  Ras2D
//
//  Created by David Hodgkinson on 24/11/2014.
//  Copyright (c) 2014 David Hodgkinson. All rights reserved.
//

#include "Director.h"

#include "Application/RasApplication.h"
#include "Controller/RenderManager.h"
#include "Util/Log.h"
#include "View/Node.h"

#include <assert.h>
#include <stdio.h>
#include <vector>

namespace Ras2D
{
    Director::Director(Ras2D::Application* application)
    : _application(application)
    {
    }

	bool Director::Init()
	{
		assert(Log::Restart());       // TODO: Move input to input manager
        
		return true;
	}

    bool Director::RegisterForUpdate(Ras2D::Node *node)
    {
        auto itr = std::find(_nodes.begin(), _nodes.end(), node);
        
        if (itr == _nodes.end())
        {
            _nodes.push_back(node);
            return true;
        }
        
        return false;
    }

    void Director::UnRegisterForUpdate(Ras2D::Node *node)
    {
        auto itr = std::find(_nodes.begin(), _nodes.end(), node);
        
        if (itr != _nodes.end())
        {
            _nodes.erase(itr);
        }
    }

	bool Director::Update(std::vector<bool> &keys, GLFWwindow* window)
	{
        for (const auto n : _nodes)
        {
            n->Update();
        }
        
        return true;
	}

	void Director::Destroy()
	{
	}
}
