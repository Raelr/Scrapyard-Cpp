#include "scypch.h"
#include "Layer.h"

namespace Scrapyard {

    Layer::Layer(const std::string& debugName) 
            : m_debugName{debugName} { }

    Layer::~Layer() {
        
    }
}