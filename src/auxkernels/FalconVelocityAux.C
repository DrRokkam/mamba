/****************************************************************/
/*             DO NOT MODIFY OR REMOVE THIS HEADER              */
/*          FALCON - Fracturing And Liquid CONvection           */
/*                                                              */
/*       (c) pending 2012 Battelle Energy Alliance, LLC         */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#include "FalconVelocityAux.h"

template<>
InputParameters validParams<FalconVelocityAux>()
{
     InputParameters params = validParams<AuxKernel>();
     params.addParam<int>("component",0,"component of the pressure vector");
     return params;
}

FalconVelocityAux::FalconVelocityAux(const InputParameters & parameters)
  :AuxKernel(parameters),
   _darcy_flux_water(getMaterialProperty<RealGradient>("darcy_flux_water")),
   _darcy_flux_steam(getMaterialProperty<RealGradient>("darcy_flux_steam")),
   _i(getParam<int>("component"))

{}

Real
FalconVelocityAux::computeValue()
{
  return _darcy_flux_water[_qp](_i);
//    return _darcy_flux_steam[_qp](_i);

}
