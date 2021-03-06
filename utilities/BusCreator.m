%% Airframe
clear elems;
a = 1;
elems(a) = Simulink.BusElement;
elems(a).Name = 'V_e';
elems(a).Dimensions = 3;
elems(a).DimensionsMode = 'Fixed';
elems(a).DataType = 'double';
elems(a).SampleTime = -1;
elems(a).Complexity = 'real';

a = a+1;
elems(a) = Simulink.BusElement;
elems(a).Name = 'X_e';
elems(a).Dimensions = 3;
elems(a).DimensionsMode = 'Fixed';
elems(a).DataType = 'double';
elems(a).SampleTime = -1;
elems(a).Complexity = 'real';

a = a+1;
elems(a) = Simulink.BusElement;
elems(a).Name = 'roll_pitch_yaw';
elems(a).Dimensions = 3;
elems(a).DimensionsMode = 'Fixed';
elems(a).DataType = 'double';
elems(a).SampleTime = -1;
elems(a).Complexity = 'real';

a = a+1;
elems(a) = Simulink.BusElement;
elems(a).Name = 'DCM_be';
elems(a).Dimensions = [3 3];
elems(a).DimensionsMode = 'Fixed';
elems(a).DataType = 'double';
elems(a).SampleTime = -1;
elems(a).Complexity = 'real';

a = a+1;
elems(a) = Simulink.BusElement;
elems(a).Name = 'V_b';
elems(a).Dimensions = 3;
elems(a).DimensionsMode = 'Fixed';
elems(a).DataType = 'double';
elems(a).SampleTime = -1;
elems(a).Complexity = 'real';

a = a+1;
elems(a) = Simulink.BusElement;
elems(a).Name = 'omega_b';
elems(a).Dimensions = 3;
elems(a).DimensionsMode = 'Fixed';
elems(a).DataType = 'double';
elems(a).SampleTime = -1;
elems(a).Complexity = 'real';

a = a+1;
elems(a) = Simulink.BusElement;
elems(a).Name = 'omega_b_dot';
elems(a).Dimensions = 3;
elems(a).DimensionsMode = 'Fixed';
elems(a).DataType = 'double';
elems(a).SampleTime = -1;
elems(a).Complexity = 'real';

a = a+1;
elems(a) = Simulink.BusElement;
elems(a).Name = 'A_bb';
elems(a).Dimensions = 3;
elems(a).DimensionsMode = 'Fixed';
elems(a).DataType = 'double';
elems(a).SampleTime = -1;
elems(a).Complexity = 'real';

a = a+1;
elems(a) = Simulink.BusElement;
elems(a).Name = 'A_be';
elems(a).Dimensions = 3;
elems(a).DimensionsMode = 'Fixed';
elems(a).DataType = 'double';
elems(a).SampleTime = -1;
elems(a).Complexity = 'real';

a = a+1;
elems(a) = Simulink.BusElement;
elems(a).Name = 'attack_angle';
elems(a).Dimensions = 2;
elems(a).DimensionsMode = 'Fixed';
elems(a).DataType = 'double';
elems(a).SampleTime = -1;
elems(a).Complexity = 'real';

a = a+1;
elems(a) = Simulink.BusElement;
elems(a).Name = 'V_air';
elems(a).Dimensions = 3;
elems(a).DimensionsMode = 'Fixed';
elems(a).DataType = 'double';
elems(a).SampleTime = -1;
elems(a).Complexity = 'real';

a = a+1;
elems(a) = Simulink.BusElement;
elems(a).Name = 'V_air_norm';
elems(a).Dimensions = 1;
elems(a).DimensionsMode = 'Fixed';
elems(a).DataType = 'double';
elems(a).SampleTime = -1;
elems(a).Complexity = 'real';

a = a+1;
elems(a) = Simulink.BusElement;
elems(a).Name = 'pos_lla';
elems(a).Dimensions = 3;
elems(a).DimensionsMode = 'Fixed';
elems(a).DataType = 'double';
elems(a).SampleTime = -1;
elems(a).Complexity = 'real';

airframe = Simulink.Bus;
airframe.Elements = elems;
%% ControlSurfaceInDegree
clear elems;
a = 1;
elems(a) = Simulink.BusElement;
elems(a).Name = 'd_ea_l';
elems(a).Dimensions = 1;
elems(a).DimensionsMode = 'Fixed';
elems(a).DataType = 'double';
elems(a).SampleTime = -1;
elems(a).Complexity = 'real';

a = a+1;
elems(a) = Simulink.BusElement;
elems(a).Name = 'd_ea_r';
elems(a).Dimensions = 1;
elems(a).DimensionsMode = 'Fixed';
elems(a).DataType = 'double';
elems(a).SampleTime = -1;
elems(a).Complexity = 'real';

a = a+1;
elems(a) = Simulink.BusElement;
elems(a).Name = 'd_ca_l';
elems(a).Dimensions = 1;
elems(a).DimensionsMode = 'Fixed';
elems(a).DataType = 'double';
elems(a).SampleTime = -1;
elems(a).Complexity = 'real';

a = a+1;
elems(a) = Simulink.BusElement;
elems(a).Name = 'd_ca_r';
elems(a).Dimensions = 1;
elems(a).DimensionsMode = 'Fixed';
elems(a).DataType = 'double';
elems(a).SampleTime = -1;
elems(a).Complexity = 'real';

a = a+1;
elems(a) = Simulink.BusElement;
elems(a).Name = 'd_r_l';
elems(a).Dimensions = 1;
elems(a).DimensionsMode = 'Fixed';
elems(a).DataType = 'double';
elems(a).SampleTime = -1;
elems(a).Complexity = 'real';

a = a+1;
elems(a) = Simulink.BusElement;
elems(a).Name = 'd_r_r';
elems(a).Dimensions = 1;
elems(a).DimensionsMode = 'Fixed';
elems(a).DataType = 'double';
elems(a).SampleTime = -1;
elems(a).Complexity = 'real';

ControlSurfaceInDegree = Simulink.Bus;
ControlSurfaceInDegree.Elements = elems;
%% AerodynamicsDataInput
% clear elems;
% a = 1;
% elems(a) = Simulink.BusElement;
% elems(a).Name = 'd_ea_l';
% elems(a).Dimensions = 1;
% elems(a).DimensionsMode = 'Fixed';
% elems(a).DataType = 'double';
% elems(a).SampleTime = -1;
% elems(a).Complexity = 'real';
% 
% a = a+1;
% elems(a) = Simulink.BusElement;
% elems(a).Name = 'd_ea_r';
% elems(a).Dimensions = 1;
% elems(a).DimensionsMode = 'Fixed';
% elems(a).DataType = 'double';
% elems(a).SampleTime = -1;
% elems(a).Complexity = 'real';
% 
% a = a+1;
% elems(a) = Simulink.BusElement;
% elems(a).Name = 'd_ca_l';
% elems(a).Dimensions = 1;
% elems(a).DimensionsMode = 'Fixed';
% elems(a).DataType = 'double';
% elems(a).SampleTime = -1;
% elems(a).Complexity = 'real';
% 
% a = a+1;
% elems(a) = Simulink.BusElement;
% elems(a).Name = 'd_ca_r';
% elems(a).Dimensions = 1;
% elems(a).DimensionsMode = 'Fixed';
% elems(a).DataType = 'double';
% elems(a).SampleTime = -1;
% elems(a).Complexity = 'real';
% 
% a = a+1;
% elems(a) = Simulink.BusElement;
% elems(a).Name = 'd_r_l';
% elems(a).Dimensions = 1;
% elems(a).DimensionsMode = 'Fixed';
% elems(a).DataType = 'double';
% elems(a).SampleTime = -1;
% elems(a).Complexity = 'real';
% 
% a = a+1;
% elems(a) = Simulink.BusElement;
% elems(a).Name = 'd_r_r';
% elems(a).Dimensions = 1;
% elems(a).DimensionsMode = 'Fixed';
% elems(a).DataType = 'double';
% elems(a).SampleTime = -1;
% elems(a).Complexity = 'real';
% 
% a = a+1;
% elems(a) = Simulink.BusElement;
% elems(a).Name = 'alpha';
% elems(a).Dimensions = 1;
% elems(a).DimensionsMode = 'Fixed';
% elems(a).DataType = 'double';
% elems(a).SampleTime = -1;
% elems(a).Complexity = 'real';
% 
% a = a+1;
% elems(a) = Simulink.BusElement;
% elems(a).Name = 'beta';
% elems(a).Dimensions = 1;
% elems(a).DimensionsMode = 'Fixed';
% elems(a).DataType = 'double';
% elems(a).SampleTime = -1;
% elems(a).Complexity = 'real';
% 
% AerodynamicsData = Simulink.Bus;
% AerodynamicsData.Elements = elems;