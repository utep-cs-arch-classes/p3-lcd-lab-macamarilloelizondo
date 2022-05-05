all:
	(cd timerLib; make install)
	(cd lcdLib; make install)
	(cd 3_moving_shapes; make)

doc:
	rm -rf doxygen_docs
	doxygen Doxyfile
clean:
	(cd timerLib; make clean)
	(cd lcdLib; make clean)
	(cd 3_moving_shapes; make clean)
	rm -rf lib h
	rm -rf doxygen_docs/*
