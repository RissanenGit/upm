#if SWIG_VERSION >= 0x030009
    %include <swiginterface.i>
    %interface_impl(upm::iCO2Sensor);
#endif

%include "stdint.i"
%include "javaupm_interfaces.i"

%include "iCO2Sensor.hpp"
%{
	#include "iCO2Sensor.hpp"
%}