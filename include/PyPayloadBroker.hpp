#ifndef PY_PAYLOAD_BROKER_HPP_
#define PY_PAYLOAD_BROKER_HPP_

#pragma once

#include "PayloadBroker.hpp"

#include <thread>
#include <mutex>
#include <queue>

namespace ds {

/**
 * PyPayloadBroker is a class designed to be used from other languages.
 * (not necessarily Python, but i'm feeling too lazy to rename at the moment)
 * 
 * It stores NVDS_PAYLOAD_META in a string and returns a null terminated char*
 * copy with get_payload()
 */
class PyPayloadBroker : public PayloadBroker {
private:
  std::string data;
  std::mutex data_lock;
public:
  PyPayloadBroker() = default;
  virtual ~PyPayloadBroker() = default;
  /**
   * Called by on_buffer when a NVDS_PAYLOAD_META is found on the buffer.
   * 
   * Returns true on success, false on failure.
   */
  virtual bool on_batch_payload(std::string* payload);
  /**
   * get a gchararray with the latest serialized batch.
   */
  virtual gchararray get_payload();
};

} // namespace ds

#endif  // PY_PAYLOAD_BROKER_HPP_