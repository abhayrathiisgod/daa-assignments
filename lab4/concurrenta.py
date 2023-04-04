from concurrent.futures import ThreadPoolExecutor
import time
import pip._vendor.requests
import requests
from bs4 import BeautifulSoup
class ConcurrentListCrawler(object):
    def __init__(self, url_list, threads):
        self.urls = url_list
        self.results = {}
        self.max_threads = threads
        print("Number of threads "+str(self.max_threads))
    def __make_request(self, url):
        try:
            r = requests.get(url=url, timeout=20)
            r.raise_for_status()
        except requests.exceptions. Timeout:
            r = requests.get(url=url, timeout=60)
        except requests.exceptions.ConnectionError:
            r = requests.get(url-query, timeout=60)
        except requests.exceptions.RequestException as e:
            raise e
        return r.url, r.text
    def __parse_results(self, url, html):
        try:
            soup = BeautifulSoup(html, 'html.parser')
            title = soup.find('title').get_text()
        except Exception as e:
            raise e
        if title:
            self.results[url] = title
    def wrapper(self, url):
        url, html = self.__make_request(url)
        self.__parse_results(url, html)

    def run_script(self):
        with ThreadPoolExecutor(max_workers=min(len(self.urls), self.max_threads)) as Executor:
            jobs = [Executor.submit(self.wrapper, u) for u in self.urls]
if __name__ == '__main__':
    q = time.time()
    example =ConcurrentListCrawler(["https://timesofindia.indiatimes.com/defaultinterstitial.cms","https://www.theguardian.com/international","https://www.apple.com/in /?afid=p238 % 7CsdUuvv563-dc_mtid_187079nc38483_pcrid_474706300243_pgrid_109516736379_ & cid=aos-IN-kwgo-brand--slid---product -","https://www.samsung.com/in/","https://www.amazon.jobs/en-gb/"], 5)
    example.run_script()
    q1 = time.time()

# print(example, results)
    for key, val in example.results.items():
        print(key+": "+val)
    print("Time taken to crawl the given web pages: "+str(q1-q))
