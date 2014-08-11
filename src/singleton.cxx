#include <cxxutils/singleton.hxx>

namespace cxxutils
{
    singleton_error::singleton_error(std::string const & what_arg)
        : std::runtime_error(what_arg)
    {
    }

    singleton_error::singleton_error(char const * what_arg)
        : std::runtime_error(what_arg)
    {
    }
}
