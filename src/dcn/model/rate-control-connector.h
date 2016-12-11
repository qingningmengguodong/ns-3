#ifndef RATE_CONTROL_CONNECTOR_H
#define RATE_CONTROL_CONNECTOR_H

#include "ns3/data-rate.h"

#include "connector.h"

namespace ns3 {
namespace dcn {

/**
 * \ingroup dcn
 *
 * \brief connector with rate control function
 * the base class of Connector wiht rate control
 * which is the base class of division/tunnel/flow(session)
 */
class RateControlConnector : public Connector
{
public:
  /**
   * \brief Get the type ID.
   * \return the object TypeId
   */
  static TypeId GetTypeId (void);

  virtual ~RateControlConnector ();
public:
  /**
   * \brief updateRateRequest
   * \return current rate request
   * called by outer layer to update the current rate
   * request.
   */
  virtual DataRate UpdateRateRequest (void) = 0;
  /**
   * \brief getRateRequest
   * \return current rate request
   * called by outer layer to get the current rate
   * request.
   */
  DataRate GetRateRequest(void) const;
  /**
   * \brief setRateResponse
   * \param rate the rate response
   * called by outer layer to set the rate allocated to this.
   */
  virtual void SetRateResponse(const DataRate &rate) = 0;

protected:
  DataRate m_rateRequest;
  DataRate m_rateResponse;
};

} //namespace dcn
} //namespace ns3

#endif // RATE_CONTROL_CONNECTOR_H
