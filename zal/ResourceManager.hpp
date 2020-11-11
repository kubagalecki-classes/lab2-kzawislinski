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

    ResourceManager(const ResourceManager& kopia)
    {
      res = new Resource{*kopia.res};
    }

    ResourceManager& operator=(const ResourceManager& kopia2)
    {
      if (this == &kopia2) return *this;
      detele res;
      res = kopia2.res;
      kopia2.res = nullptr;
      return *this;
    }

    ResourceManager(ResourceManager&& kopia3)
    {
      res=kopia3.res;
      kopia3.res=nullptr;
    }

    ResourceManager& operator=(ResourceManager&& kopia4)
    {
      if(res=kopia4.res) return *this;
      delete res;
      res=kopia4.res;
      kopia4.res=nullptr;
      return *this;
    }

    double get(){return res->get();}


    
    
    ~ResourceManager()
    {
      delete res;
    }

    
};
