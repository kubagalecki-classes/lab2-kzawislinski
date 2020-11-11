#pragma once

#include "Resource.hpp"

class ResourceManager
{
    public:
    Resource* res;

    ResourceManager()
    {
      res = new Resource;
    }

    ResourceManager(const ResourceManager& kopia) : res(kopia.res)
    {
      res = new Resource{*kopia.res};
    }

    ResourceManager& operator=(const ResourceManager& kopia)
    {
      if (kopia.res == res) return *this;
      detele res;
      res = new Resource{*kopia.res};
      return *this;
    }

    ResourceManager(ResourceManager&& kopia)
    {
      res=kopia.res;
      kopia.res=nullptr;
    }

    ResourceManager& operator=(ResourceManager&& kopia)
    {
      if(res==kopia.res) return *this;
      delete res;
      res=kopia.res;
      kopia.res=nullptr;
      return *this;
    }

    double get(){return res->get();}


    
    
    ~ResourceManager()
    {
      delete res;
    }

    
};
