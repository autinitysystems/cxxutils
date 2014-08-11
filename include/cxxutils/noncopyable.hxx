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

namespace cxxutils
{
    /**
     *  \brief Parent class for noncopyable classes.
     *
     *  A class can inherit from this class to become noncopyable.
     *
     *  \note You must use \a private inheritance for this to work.
     *  \note The child class mght still be movable.
     */
    class noncopyable
    {
        noncopyable(noncopyable const &) = delete; ///< The deleted copy constructor.
        noncopyable & operator = (noncopyable const &) = delete; ///< The deleted copy assignment operator.
    };
}

#endif // CXXUTILS_NONCOPYABLE_HXX
