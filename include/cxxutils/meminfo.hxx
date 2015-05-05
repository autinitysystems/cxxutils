#ifndef CXXUTILS_MEMINFO_HXX
#define CXXUTILS_MEMINFO_HXX

/**
 *  \file meminfo.hxx
 *
 *  \brief Class retrieving information about the memory.
 *
 *  This class retrieves information about physical and virtual RAM.
 *  Its functionality is very operating system specific.
 */

// Standard library
#include <cstdint>

namespace cxxutils
{
    /**
     *  \brief Class retrieving information about the memory.
     *
     *  This class retrieves information about physical and virtual RAM.
     *  Its functionality is very operating system specific.
     * 
     *  \note Not all functions are supported on all operating systems.
     */
    struct meminfo
    {
        /**
         * \brief Retrieve total physical memory in bytes.
         * 
         * This function retrieves the total physical memory in bytes.
         * 
         * \return The total physical memory in bytes or 0 if it is not supported.
         */
        static std::uint64_t phys_total();
        
        /**
         * \brief Retrieve available physical memory in bytes.
         * 
         * This function retrieves the available physical memory in bytes.
         * 
         * \return The available physical memory in bytes or 0 if it is not supported.
         */
        static std::uint64_t phys_avail();
        
        /**
         * \brief Retrieve total virtual memory in bytes.
         * 
         * This function retrieves the total virtual memory in bytes.
         * 
         * \return The total virtual memory in bytes or 0 if it is not supported.
         * 
         * \remarks Currently only supported on Windows and Linux.
         */
        static std::uint64_t virt_total();
        
        /**
         * \brief Retrieve available virtual memory in bytes.
         * 
         * This function retrieves the available virtual memory in bytes.
         * 
         * \return The available virtual memory in bytes or 0 if it is not supported.
         * 
         * \remarks Currently only supported on Windows and Linux.
         */
        static std::uint64_t virt_avail();
    };
}

#endif // CXXUTILS_MEMINFO_HXX
