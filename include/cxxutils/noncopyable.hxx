/*************************************************
 * Copyright © 2015, afr-consulting GmbH         *
 *                                               *
 * See the file COPYING for copying permissions. *
 *************************************************/

#ifndef CXXUTILS_NONCOPYABLE_HXX
#define CXXUTILS_NONCOPYABLE_HXX

/**
 *  \file noncopyable.hxx
 *
 *  \brief Parent class for noncopyable classes.
 *
 *  This file contains the noncopyable class. Other classes
 *  can inherit its noncopyability.
 */

// Internal
#include <cxx11_features.hxx>

namespace cxxutils
{
    /**
     *  \brief Parent class for noncopyable classes.
     *
     *  A class can inherit from this class to become noncopyable.
     *
     *  \note You must use \a private inheritance for this to work.
     *  \note The child class might still be movable.
     */
#if defined(CXX11_FEATURE_DEFAULTDELETE)
    struct noncopyable
    {
        noncopyable() = default; ///< Default constructor.
        virtual ~noncopyable() = default; ///< Default destructor.
        noncopyable(noncopyable const &) = delete; ///< The deleted copy constructor.
        noncopyable & operator = (noncopyable const &) = delete; ///< The deleted copy assignment operator.
    };
#else // !CXX11_FEATURE_DEFAULTDELETE
    struct noncopyable
    {
        noncopyable() {} ///< Default constructor.
        virtual ~noncopyable() {} ///< Default destructor.

    private:
        noncopyable(noncopyable const &); ///< The deleted copy constructor.
        noncopyable & operator = (noncopyable const &); ///< The deleted copy assignment operator.
    };
#endif // CXX11_FEATURE_DEFAULTDELETE
}

#endif // CXXUTILS_NONCOPYABLE_HXX
