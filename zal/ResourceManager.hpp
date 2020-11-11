#pragma once

#include "Resource.hpp"

class ResourceManager
{
    public:
    Resource* wsk;
    ResourceManager ( ){wsk= new Resource; }
    ResourceManager ( const ResourceManager& re):wsk(re.wsk) {wsk= new Resource{*re.wsk};}
    ResourceManager& operator=(const ResourceManager& re){
      if(wsk == re.wsk) return *this;
      delete wsk;
      wsk= new Resource{*re.wsk};
      return *this;
     
    }
    ResourceManager(ResourceManager&& re){
      wsk=re.wsk;
      re.wsk=nullptr;
      
    }
    ResourceManager& operator=(ResourceManager&& re){
      if(wsk==re.wsk) return *this;
      delete wsk;
      wsk= re.wsk;
      re.wsk=nullptr;
      return *this;
     
    }
    double get() {return wsk->get();}
    ~ResourceManager() { delete wsk; }
};
