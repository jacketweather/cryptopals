import requests
import re
from collections import Counter

def main() -> None:
	txt = requests.get("http://www.gutenberg.org/files/161/161-h/161-h.htm").text
	txt = re.sub("[^a-zA-Z ]", "", txt).lower()
	ctr = Counter(txt)
	print({x: round(ctr[x] / sum(ctr.values()), 5) for x in ctr})

if __name__ == "__main__":
	main()