

include common.mk

default: test/HelloWorld

test/HelloWorld: $(obj-HelloWorld)
	$(CPP) $^ -o $@ $(LIBRARY) $(SYSLIBS)

%.o: %.cpp
	$(CPP) -Wall $(INCLUDE) -c $< -o $@


clean:
	rm -rf $(obj-HelloWorld) test/HelloWorld



