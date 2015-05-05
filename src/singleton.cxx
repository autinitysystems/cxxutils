/*************************************************
 * Copyright © 2015, afr-consulting GmbH         *
 *                                               *
 * See the file COPYING for copying permissions. *
 *************************************************/

#include <cxxutils/singleton.hxx>

namespace cxxutils
{
    std::string const singleton_error::already_exists = "A singleton instance already exists.";
    std::string const singleton_error::unexpected = "Something really bad and unexplanable happened.";
    std::string const singleton_error::access_non_existent = "Trying to access non-existent singleton instance.";

    singleton_error::singleton_error(std::string const & what_arg)
        : std::runtime_error(what_arg)
    {
    }

    singleton_error::singleton_error(char const * what_arg)
        : std::runtime_error(what_arg)
    {
    }
}
