import sys
import math

def generate_sqrt_table(filename):
	TABLE = "double sqrtTable[] = {"
	SQRTs = [str(math.sqrt(x)) for x in xrange(101)]
	TABLE += ", ".join(SQRTs)
	TABLE += "};\n"
	f = open(filename, "w")
	f.write(TABLE)
	f.close()

if len(sys.argv) == 2:
	generate_sqrt_table(sys.argv[1])
