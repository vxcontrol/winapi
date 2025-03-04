#ifndef WUTILS_H
#define WUTILS_H
typedef int Ref;

extern int mutex_locked;

enum {
    INTEGER = 1,
    REF_IDX = 2,
    DISCARD = 4
};

Ref make_ref(lua_State *L, int idx);
void release_ref(lua_State *L, Ref ref);
int push_ref(lua_State *L, Ref ref);
const char *last_error(int err);
int push_error_msg(lua_State *L, LPCSTR msg) ;
int push_error(lua_State *L);
int push_perror(lua_State *L, const char *prefix);
int push_error_code(lua_State *L, int err);
int push_ok(lua_State *L);
int push_bool(lua_State *L, int bval);
void throw_error(lua_State *L, LPCSTR msg);
BOOL call_lua_direct(lua_State *L, Ref ref, int idx, LPCSTR text, int discard);
void make_message_window();
BOOL call_lua(lua_State *L, Ref ref, int idx, LPCSTR text, int discard);
void lock_mutex();
void release_mutex();
void setup_mutex();

// encoding and converting text
void set_encoding(int e);
int get_encoding();

LPWSTR wstring_buff(LPCSTR text, LPWSTR wbuf, int bufsz);
int push_wstring_l(lua_State *L, LPCWSTR us, int len);
int push_wstring(lua_State *L, LPCWSTR us);

HKEY split_registry_key(LPCSTR path, char *keypath);
int mb_const (LPCSTR name);
LPCSTR mb_result (int res);
BOOL create_process_in_job(
    HANDLE hJob,
    LPCWSTR lpApplicationName,
    LPWSTR lpCommandLine,
    LPSECURITY_ATTRIBUTES lpProcessAttributes,
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    BOOL bInheritHandles,
    DWORD dwCreationFlags,
    LPVOID lpEnvironment,
    LPCWSTR lpCurrentDirectory,
    LPSTARTUPINFOW lpStartupInfo,
    LPPROCESS_INFORMATION ppi);

#endif
