require 'winapi'
local r,w = winapi.pipe()
local m = winapi.mutex()

local function lprint(...)
  m:lock()
  print(...)
  m:release()
end

local function long(name)
  lprint('hello',name)
  for i = 1,2 do
    m:lock()
    w:write(name..tostring(i))
    m:release()
  end
end

r:read_async(function(s)
  lprint(s)
end)

local T = {}
T[1] = winapi.thread(long, 'john')
T[2] = winapi.thread(long, 'jane')
T[3] = winapi.thread(long, 'june')

winapi.wait_for_processes(T, true)
print 'thread test was finished'

local e = winapi.event()
local count = 1
local finished

winapi.make_timer(500, function()
    print 'tick'
    if count == 5 then
        print 'finished!'
        finished = true
    end
    e:signal()
    count = count + 1
end)

while not finished do
    e:wait()
    print 'gotcha'
end
print 'events test was finished'
