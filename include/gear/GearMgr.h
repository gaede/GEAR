// -*- C++ -*-
#ifndef GEAR_GEARMGR_H
#define GEAR_GEARMGR_H 1

#include <string>
#include <vector>

#include "GEAR.h"
#include "gear/GearParameters.h"





namespace gear {

class BField;
class CalorimeterParameters;
class GearDistanceProperties;
class GearPointProperties;
class TrackerPlanesParameters;
class SiPlanesParameters;
class TPCParameters;
class ZPlanarParameters ;
class FTDParameters ;
class SimpleMaterial ;
class MeasurementSurfaceStore;
  
  /** Abstract interface for a manager class that returns the Gear classes for the 
 *  relevant subdetectors.
 * 
 *
 * @author F. Gaede, DESY
 * @version $Id$
 */
  class GearMgr {
    
  public: 
    /// Destructor.
    virtual ~GearMgr() { /* nop */; }
    
    /** The unique detector name - typically the model name used in the simulation program
     */
    virtual const std::string & getDetectorName() const = 0;

    /** Get named parameters for key. This can be used to describe a subdetector that is not 
     *  yet forseen in the Gear API.
     * 
     *  @throws UnknownParameterException
     */
    virtual const GearParameters & getGearParameters(const std::string & key) const throw (UnknownParameterException, std::exception )  = 0;

    /** Get the B field map.
     *
     *  @throws UnknownParameterException
     */
    virtual const BField & getBField() const throw (UnknownParameterException, std::exception )  = 0;

    /** Get the TPCParameters.
     *
     *  @throws UnknownParameterException
     */
    virtual const TPCParameters & getTPCParameters() const throw (UnknownParameterException, std::exception )  = 0;

    /** Get the Ecal barrel parameters.
     *
     *  @throws UnknownParameterException
     */
    virtual const CalorimeterParameters & getEcalBarrelParameters() const throw (UnknownParameterException, std::exception )  = 0;

    /** Get the Ecal endcap parameters.
     *
     *  @throws UnknownParameterException
     */
    virtual const CalorimeterParameters & getEcalEndcapParameters() const throw (UnknownParameterException, std::exception )  = 0;

    /** Get the Ecal plug parameters.
     *
     *  @throws UnknownParameterException
     */
    virtual const CalorimeterParameters & getEcalPlugParameters() const throw (UnknownParameterException, std::exception )  = 0;

    /** Get the Yoke barrel parameters.
     *
     *  @throws UnknownParameterException
     */
    virtual const CalorimeterParameters & getYokeBarrelParameters() const throw (UnknownParameterException, std::exception )  = 0;

    /** Get the Yoke endcap parameters.
     *
     *  @throws UnknownParameterException
     */
    virtual const CalorimeterParameters & getYokeEndcapParameters() const throw (UnknownParameterException, std::exception )  = 0;

    /** Get the Yoke plug parameters.
     *
     *  @throws UnknownParameterException
     */
    virtual const CalorimeterParameters & getYokePlugParameters() const throw (UnknownParameterException, std::exception )  = 0;

    /** Get the Hcal barrel parameters.
     *
     *  @throws UnknownParameterException
     */
    virtual const CalorimeterParameters & getHcalBarrelParameters() const throw (UnknownParameterException, std::exception )  = 0;

    /** Get the Hcal endcap parameters.
     *
     *  @throws UnknownParameterException
     */
    virtual const CalorimeterParameters & getHcalEndcapParameters() const throw (UnknownParameterException, std::exception )  = 0;

    /** Get the Hcal ring parameters.
     *
     *  @throws UnknownParameterException
     */
    virtual const CalorimeterParameters & getHcalRingParameters() const throw (UnknownParameterException, std::exception )  = 0;

    /** Get the Lcal parameters.
     *
     *  @throws UnknownParameterException
     */
    virtual const CalorimeterParameters & getLcalParameters() const throw (UnknownParameterException, std::exception )  = 0;

    /** Get the LHcal parameters.
     *
     *  @throws UnknownParameterException
     */
    virtual const CalorimeterParameters & getLHcalParameters() const throw (UnknownParameterException, std::exception )  = 0;

    /** Get the BeamCal parameters.
     *
     *  @throws UnknownParameterException
     */
    virtual const CalorimeterParameters & getBeamCalParameters() const throw (UnknownParameterException, std::exception )  = 0;

    /** Get the VXD parameters.
     *
     *  @throws UnknownParameterException
     */
    virtual const ZPlanarParameters & getVXDParameters() const throw (UnknownParameterException, std::exception )  = 0;

    /** Get the FTD parameters.
     *
     *  @throws UnknownParameterException
     */
    virtual const FTDParameters & getFTDParameters() const throw (UnknownParameterException, std::exception )  = 0;

    /** Get the SIT parameters.
     *
     *  @throws UnknownParameterException
     */
    virtual const ZPlanarParameters & getSITParameters() const throw (UnknownParameterException, std::exception )  = 0;

    /** Get the SET parameters.
     *
     *  @throws UnknownParameterException
     */
    virtual const ZPlanarParameters & getSETParameters() const throw (UnknownParameterException, std::exception )  = 0;

    /** Get the TrackerPlanes parameters.
     *
     *  @throws UnknownParameterException
     */
    virtual const TrackerPlanesParameters & getTrackerPlanesParameters() const throw (UnknownParameterException, std::exception )  = 0;

    /** Get the SiPlanes parameters.
     *
     *  @throws UnknownParameterException
     */
    virtual const SiPlanesParameters & getSiPlanesParameters() const throw (UnknownParameterException, std::exception )  = 0;

    /** Get the point properties object.
     * 
     *  @throws NotImplementedException
     */
    virtual const GearPointProperties & getPointProperties() const throw (NotImplementedException, std::exception )  = 0;

    /** Get the distance properties object.
     * 
     *  @throws NotImplementedException
     */
    virtual const GearDistanceProperties & getDistanceProperties() const throw (NotImplementedException, std::exception )  = 0;

    /** Keys of all GearParameters. 
     */ 
    virtual const std::vector<std::string>  & getGearParameterKeys() const = 0;

    
    /** Return the SimpleMaterial for the given name throws UnknownParameterException if no material is unknown.*/
    virtual const SimpleMaterial& getSimpleMaterial( const std::string name ) const throw (UnknownParameterException, std::exception )  = 0 ;
    
    /** Names of registered materials.
     */ 
    virtual const std::vector<std::string>  & getMaterialNames() const = 0;

    /** Return the MeasurementSurfaceStore
     */
    virtual MeasurementSurfaceStore& getMeasurementSurfaceStore() const = 0 ;

    
    /** Set detector name.
     */
    virtual void setDetectorName(const std::string & name) = 0;

    /** Set named parameters for key. This can be used to describe a subdetector that is not 
     *  yet forseen in the Gear API.
     */
    virtual void setGearParameters(const std::string & key, GearParameters * gearParameters) = 0;

    /** Set the BField.
     */
    virtual void setBField(BField * bField) = 0;

    /** Set the TPCParameters.
     */
    virtual void setTPCParameters(TPCParameters * tpcParameters) = 0;

    /** Set the EcalBarrelParameters.
     */
    virtual void setEcalBarrelParameters(CalorimeterParameters * ecalBarrelParameters) = 0;

    /** Set the EcalEndcapParameters.
     */
    virtual void setEcalEndcapParameters(CalorimeterParameters * ecalEndcapParameters) = 0;

    /** Set the EcalPlugParameters.
     */
    virtual void setEcalPlugParameters(CalorimeterParameters * ecalPlugParameters) = 0;

    /** Set the YokeBarrelParameters.
     */
    virtual void setYokeBarrelParameters(CalorimeterParameters * ecalBarrelParameters) = 0;

    /** Set the YokeEndcapParameters.
     */
    virtual void setYokeEndcapParameters(CalorimeterParameters * ecalEndcapParameters) = 0;

    /** Set the YokePlugParameters.
     */
    virtual void setYokePlugParameters(CalorimeterParameters * ecalPlugParameters) = 0;

    /** Set the HcalBarrelParameters.
     */
    virtual void setHcalBarrelParameters(CalorimeterParameters * hcalBarrelParameters) = 0;

    /** Set the HcalEndcapParameters.
     */
    virtual void setHcalEndcapParameters(CalorimeterParameters * hcalEndcapParameters) = 0;

    /** Set the HcalRingParameters.
     */
    virtual void setHcalRingParameters(CalorimeterParameters * hcalRingParameters) = 0;

    /** Set the VXDParameters.
     */
    virtual void setVXDParameters(ZPlanarParameters * vxdParameters) = 0;

    /** Set the FTDParameters.
     */
    virtual void setFTDParameters(FTDParameters * ftdParameters) = 0;

    /** Set the SITParameters.
     */
    virtual void setSITParameters(ZPlanarParameters * sitParameters) = 0;

    /** Set the SETParameters.
     */
    virtual void setSETParameters(ZPlanarParameters * setParameters) = 0;

    /** Set the TrackerPlanesParameters.
     */
    virtual void setTrackerPlanesParameters(TrackerPlanesParameters * trackerplanesParameters) = 0;

    /** Set the SiPlanesParameters.
     */
    virtual void setSiPlanesParameters(SiPlanesParameters * siplanesParameters) = 0;

    /** Set the LcalParameters.
     */
    virtual void setLcalParameters(CalorimeterParameters * lcalParameters) = 0;

    /** Set the LHcalParameters.
     */
    virtual void setLHcalParameters(CalorimeterParameters * lhcalParameters) = 0;

    /** Set the BeamCalParameters.
     */
    virtual void setBeamCalParameters(CalorimeterParameters * beamcalParameters) = 0;

    /** Set the point properties object.
     */
    virtual void setPointProperties(GearPointProperties * pointProperties) = 0;

    /** Set the distance properties object.
     */
    virtual void setDistanceProperties(GearDistanceProperties * distanceProperties) = 0;

    /** Register the SimpleMaterial with  SimpleMaterial::getName() - throws Exception if a material of the given name has already been added.
     *  This takes ownership of the SimpleMaterial object.
     */
    virtual void registerSimpleMaterial( const SimpleMaterial* material ) throw( Exception , std::exception ) = 0 ;
    

  }; // class
} // namespace gear
#endif /* ifndef GEAR_GEARMGR_H */
