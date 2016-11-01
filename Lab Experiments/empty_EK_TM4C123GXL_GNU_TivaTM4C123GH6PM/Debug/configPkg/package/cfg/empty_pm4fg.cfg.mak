# invoke SourceDir generated makefile for empty.pm4fg
empty.pm4fg: .libraries,empty.pm4fg
.libraries,empty.pm4fg: package/cfg/empty_pm4fg.xdl
	$(MAKE) -f C:\Users\Koona\Documents\MTech\EmbeddedSystems\CCSWorkspace\empty_EK_TM4C123GXL_GNU_TivaTM4C123GH6PM/src/makefile.libs

clean::
	$(MAKE) -f C:\Users\Koona\Documents\MTech\EmbeddedSystems\CCSWorkspace\empty_EK_TM4C123GXL_GNU_TivaTM4C123GH6PM/src/makefile.libs clean

