! (C) Copyright 2013-2014 ECMWF.

!------------------------------------------------------------------------------

TYPE, extends(object_type) :: atlas_JSON
  character(kind=c_char,len=1), allocatable, private :: string(:)
contains
  procedure :: str => atlas_JSON__str
END TYPE atlas_JSON

interface atlas_JSON
  module procedure atlas_JSON_str
end interface

!------------------------------------------------------------------------------
