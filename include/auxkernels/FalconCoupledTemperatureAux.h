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

#ifndef FALCONCOUPLEDTEMPERATUREAUX_H
#define FALCONCOUPLEDTEMPERATUREAUX_H

#include "AuxKernel.h"
#include "WaterSteamEOS.h"


//Forward Declarations
class FalconCoupledTemperatureAux;

template<>
InputParameters validParams<FalconCoupledTemperatureAux>();

/** 
 * Coupled auxiliary value
 */
class FalconCoupledTemperatureAux : public AuxKernel
{
public:
    
    /**
     * Factory constructor, takes parameters so that all derived classes can be built using the same
     * constructor.
     */
    FalconCoupledTemperatureAux(const std::string & name, InputParameters parameters);
    
    virtual ~FalconCoupledTemperatureAux() {};
    
protected:
    virtual Real computeValue();
    
    const WaterSteamEOS & _water_steam_properties;
    VariableValue & _pressure;
    VariableValue & _enthalpy;
    Real _input_temperature;
                     
};

#endif //FALCONCOUPLEDTEMPERATUREAUX_H
