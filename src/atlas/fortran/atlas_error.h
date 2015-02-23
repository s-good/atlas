#ifndef atlas_fortran_atlas_error_h
#define atlas_fortran_atlas_error_h

#include "eckit/exception/Exceptions.h"

namespace atlas {

static const int atlas_err_cleared         =  1 ;
static const int atlas_err_noerr           =  0  ;
static const int atlas_err_exception       = -1  ;
static const int atlas_err_usererror       = -2  ;
static const int atlas_err_seriousbug      = -3  ;
static const int atlas_err_notimplemented  = -4  ;
static const int atlas_err_assertionfailed = -5  ;
static const int atlas_err_badparameter    = -6  ;
static const int atlas_err_outofrange      = -7  ;
static const int atlas_err_stop            = -100;
static const int atlas_err_abort           = -101;
static const int atlas_err_cancel          = -102;
static const int atlas_err_readerror       = -200;
static const int atlas_err_writeerror      = -201;
static const int atlas_err_unknown         = -999;

void handle_error(const eckit::Exception& exception, const int err_code);

#define ATLAS_ERROR_HANDLING(STATEMENTS) \
do { try{ STATEMENTS; } \
catch( eckit::SeriousBug& e )      { handle_error(e,atlas_err_seriousbug); } \
catch( eckit::NotImplemented& e )  { handle_error(e,atlas_err_notimplemented); } \
catch( eckit::OutOfRange& e )      { handle_error(e,atlas_err_outofrange); } \
catch( eckit::UserError& e )       { handle_error(e,atlas_err_usererror); } \
catch( eckit::AssertionFailed& e ) { handle_error(e,atlas_err_assertionfailed); } \
catch( eckit::BadParameter& e )    { handle_error(e,atlas_err_badparameter); } \
catch( eckit::ReadError&  e )      { handle_error(e,atlas_err_readerror);  } \
catch( eckit::WriteError&  e )     { handle_error(e,atlas_err_writeerror);  } \
catch( eckit::Exception&  e )      { handle_error(e,atlas_err_exception);  } \
catch( ... ) { handle_error(Exception("Unknown exception"),atlas_err_exception); } \
} while( 0 )
  

class Error
{
private: 
  Error();
  
public:
  static Error& instance();
    
  int code() const { return code_; }
  
  const std::string& msg() const { return msg_; }
  
  bool throws() const { return throws_; }
  
  bool backtrace() const { return backtrace_; }

  bool aborts() const { return aborts_; }
  
  void set_code( int c ) { code_ = c; }

  void set_msg( const std::string& m ) { msg_ = m; }

  void set_aborts( bool b ) { aborts_ = b; }
  
  void set_throws( bool b ) { throws_ = b; }

  void set_backtrace( bool b ) { backtrace_ = b; }
  
  void clear();
  
private:
  std::string msg_;
  int code_;
  bool aborts_;
  bool throws_;
  bool backtrace_;
};

}

extern "C"
{
  void atlas__abort (char* msg, char* file, int line, char* function);
  void atlas__throw_exception (char* msg, char* file, int line, char* function);
  void atlas__throw_notimplemented (char* msg, char* file, int line, char* function);
  void atlas__throw_outofrange (char* msg, char* file, int line, char* function);
  void atlas__throw_seriousbug (char* msg, char* file, int line, char* function);
  void atlas__throw_usererror (char* msg, char* file, int line, char* function);
  void atlas__throw_assertionfailed (char* msg, char* file, int line, char* function);
  void atlas__throw_ (char* msg, char* file, int line, char* function);
  int atlas__Error_code ();
  void atlas__Error_clear ();
  void atlas__Error_success ();
  void atlas__Error_set_aborts (int on_off);
  void atlas__Error_set_throws (int on_off);
  void atlas__Error_set_backtrace (int on_off);
  char* atlas__Error_msg ();
  void atlas__error_example();
}

#endif
