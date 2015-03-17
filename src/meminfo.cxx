#include <cxxutils/meminfo.hxx>

#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#elif defined(__unix__) || defined(__unix) || defined(unix) || (defined(__APPLE__) && defined(__MACH__))
#include <unistd.h>
#include <sys/types.h>
#include <sys/param.h>
#if defined(BSD)
#include <sys/sysctl.h>
#endif
#if defined(__linux__)
#include <sys/sysinfo.h>
#endif
#endif


namespace cxxutils
{
    std::uint64_t meminfo::phys_total()
    {
#if defined(_WIN32) && (defined(__CYGWIN__) || defined(__CYGWIN32__))
        /* Windows with Cygwin... does not support GlobalMemoryStatusEx */
        MEMORYSTATUS status;
        status.dwLength = sizeof(status);
        GlobalMemoryStatus(&status);
        return static_cast<std::uint64_t>(status.dwTotalPhys);
#elif defined(_WIN32)
        /* Windows */
        MEMORYSTATUSEX status;
        status.dwLength = sizeof(status);
        GlobalMemoryStatusEx(&status);
        return static_cast<std::uint64_t>(status.ullTotalPhys);
#elif defined(__unix__) || defined(__unix) || defined(unix) || (defined(__APPLE__) && defined(__MACH__))
        /* UNIX and variants */
#if defined(CTL_HW) && (defined(HW_MEMSIZE) || defined(HW_PHYSMEM64))
        int mib[2] = { CTL_HW };
#if defined(HW_MEMSIZE)
        mib[1] = HW_MEMSIZE;
#elif defined(HW_PHYSMEM64)
        mib[1] = HW_PHYSMEM64;
#endif
        std::uint64_t size = 0;
        std::size_t len = sizeof(size);
        if (sysctl(mib, 2, &size, &len, nullptr, 0) == 0)
            return size;
        return 0;
#elif defined(_SC_AIX_REALMEM)
        return static_cast<std::uint64_t>(sysconf(_SC_AIX_REALMEM) * 1024ULL);
#elif defined(_SC_PHYS_PAGES) && defined(_SC_PAGE_SIZE)
        return static_cast<std::uint64_t>(sysconf(_SC_PHYS_PAGES)) * static_cast<std::uint64_t>(sysconf(_SC_PAGE_SIZE));
#elif defined(CTL_HW) && (defined(HW_PHYSMEM) || defined(HW_REALMEM))
        int mib[2] = { CTL_HW };
#if defined(HW_REALMEM)
        mib[1] = HW_REALMEM;
#elif defined(HW_PHYSMEM)
        mib[1] = HW_PHYSMEM;
#endif
        std::uint64_t size = 0;
        std::size_t len = sizeof(size);
        if (sysctl(mib, 2, &size, &len, nullptr, 0) == 0)
            return size;
        return 0;
#else
        return 0;
#endif /* UNIX and variants */
#else
        return 0;
#endif
    }
    
    std::uint64_t meminfo::phys_avail()
    {
#if defined(_WIN32) && (defined(__CYGWIN__) || defined(__CYGWIN32__))
        /* Windows with Cygwin... does not support GlobalMemoryStatusEx */
        MEMORYSTATUS status;
        status.dwLength = sizeof(status);
        GlobalMemoryStatus(&status);
        return static_cast<std::uint64_t>(status.dwAvailPhys);
#elif defined(_WIN32)
        /* Windows */
        MEMORYSTATUSEX status;
        status.dwLength = sizeof(status);
        GlobalMemoryStatusEx(&status);
        return static_cast<std::uint64_t>(status.ullAvailPhys);
#elif defined(__unix__) || defined(__unix) || defined(unix) || (defined(__APPLE__) && defined(__MACH__))
        /* UNIX and variants */
#if defined(_SC_AVPHYS_PAGES) && defined(_SC_PAGE_SIZE)
        return static_cast<std::uint64_t>(sysconf(_SC_AVPHYS_PAGES)) * static_cast<std::uint64_t>(sysconf(_SC_PAGE_SIZE));
#else
        return 0;
#endif /* UNIX and variants */
#else
        return 0;
#endif
    }
    
    std::uint64_t meminfo::virt_total()
    {
#if defined(_WIN32) && (defined(__CYGWIN__) || defined(__CYGWIN32__))
        /* Windows with Cygwin... does not support GlobalMemoryStatusEx */
        MEMORYSTATUS status;
        status.dwLength = sizeof(status);
        GlobalMemoryStatus(&status);
        return static_cast<std::uint64_t>(status.dwTotalVirtual);
#elif defined(_WIN32)
        /* Windows */
        MEMORYSTATUSEX status;
        status.dwLength = sizeof(status);
        GlobalMemoryStatusEx(&status);
        return static_cast<std::uint64_t>(status.ullTotalVirtual);
#elif defined(__linux__)
        struct sysinfo info;
        sysinfo(&info);
        std::uint64_t virtmem = info.totalram;
        virtmem += info.totalswap;
        virtmem *= info.mem_unit;
        return virtmem;
#else
        return 0;
#endif
    }
    
    std::uint64_t meminfo::virt_avail()
    {
#if defined(_WIN32) && (defined(__CYGWIN__) || defined(__CYGWIN32__))
        /* Windows with Cygwin... does not support GlobalMemoryStatusEx */
        MEMORYSTATUS status;
        status.dwLength = sizeof(status);
        GlobalMemoryStatus(&status);
        return static_cast<std::uint64_t>(status.dwAvailVirtual);
#elif defined(_WIN32)
        /* Windows */
        MEMORYSTATUSEX status;
        status.dwLength = sizeof(status);
        GlobalMemoryStatusEx(&status);
        return static_cast<std::uint64_t>(status.ullAvailVirtual);
#elif defined(__linux__)
        struct sysinfo info;
        sysinfo(&info);
        std::uint64_t virtmem = info.freeram;
        virtmem += info.freeswap;
        virtmem *= info.mem_unit;
        return virtmem;
#else
        return 0;
#endif
    }
}
