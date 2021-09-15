#pragma once

#include "file_io_by_type.hpp"

namespace pldm
{
namespace responder
{

using LicType = uint16_t;

/** @class LicenseHandler
 *
 *  @brief Inherits and implements FileHandler. This class is used
 *  to read license
 */
class LicenseHandler : public FileHandler
{
  public:
    /** @brief Handler constructor
     */
    LicenseHandler(uint32_t fileHandle, uint16_t fileType) :
        FileHandler(fileHandle), licType(fileType)
    {}

    virtual int writeFromMemory(uint32_t /*offset*/, uint32_t /*length*/,
                                uint64_t /*address*/,
                                oem_platform::Handler* /*oemPlatformHandler*/)
    {
        return PLDM_ERROR_UNSUPPORTED_PLDM_CMD;
    }

    virtual int readIntoMemory(uint32_t /*offset*/, uint32_t& /*length*/,
                               uint64_t /*address*/,
                               oem_platform::Handler* /*oemPlatformHandler*/)
    {
        return PLDM_ERROR_UNSUPPORTED_PLDM_CMD;
    }

    virtual int read(uint32_t offset, uint32_t& length, Response& response,
                     oem_platform::Handler* /*oemPlatformHandler*/);

    virtual int write(const char* /*buffer*/, uint32_t /*offset*/,
                      uint32_t& /*length*/,
                      oem_platform::Handler* /*oemPlatformHandler*/)
    {
        return PLDM_ERROR_UNSUPPORTED_PLDM_CMD;
    }

    virtual int fileAck(uint8_t /*fileStatus*/)
    {
        return PLDM_ERROR_UNSUPPORTED_PLDM_CMD;
    }

    virtual int newFileAvailable(uint64_t /*length*/)
    {
        return PLDM_ERROR_UNSUPPORTED_PLDM_CMD;
    }

    virtual int fileAckWithMetaData(uint32_t metaDataValue);

    /** @brief LicenseHandler destructor
     */
    ~LicenseHandler()
    {}

  private:
    uint16_t licType; //!< type of the certificate

    enum class Status
    {
        InvalidLicense,
        Activated,
        Pending,
        ActivationFailed,
        IncorrectSystem,
        InvalidHostState,
        IncorrectSequence
    };
};
} // namespace responder
} // namespace pldm