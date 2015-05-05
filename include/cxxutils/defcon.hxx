/*************************************************
 * Copyright © 2015, afr-consulting GmbH         *
 *                                               *
 * See the file COPYING for copying permissions. *
 *************************************************/

#ifndef CXXUTILS_DEFCON_HXX
#define CXXUTILS_DEFCON_HXX

/**
 *  \file defcon.hxx
 *
 *  \brief Utility class to default-construct objects of classes with lengthy names.
 *
 *  This file contains the \a none object of an anonymous class.
 *  It can be used e.g. in return statements to return a default-constructed
 *  object of a class with a lengthy name.
 */

namespace cxxutils
{
    static struct
    {
        template <typename Target>
        operator Target () const
        {
            return Target();
        }
    } const defcon; ///< Nice helper to default-construct objects of classes with lengthy names.
}

#endif // CXXUTILS_DEFCON_HXX
