all:
  cd Upper && nmake TOP=$(MAKEDIR)\Upper

clean:
  cd Upper && nmake TOP=$(MAKEDIR)\Upper clean

