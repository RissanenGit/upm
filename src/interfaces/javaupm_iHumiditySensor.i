#if SWIG_VERSION >= 0x030009
    %include <swiginterface.i>
    %interface_impl(upm::iHumiditySensor);
#endif

%include "javaupm_interfaces.i"

%include "iHumiditySensor.hpp"
%{
	#include "iHumiditySensor.hpp"
%}