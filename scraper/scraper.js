const puppeteer = require('puppeteer');
const address = 'https://www.indeed.com/';
const options = {
	path: 'pdf/web.pdf',
	format: 'A4',
}
//Throw while loop, Put multiple addresses in array. Loop through address
let scrape = async () => {
  const browser = await puppeteer.launch({args: ['--no-sandbox', '--disable-setuid-sandbox']});
  const page = await browser.newPage();
  await page.goto(address);
  await page.waitFor(1000);
  console.log(address);

  //scrape here

  //waits for navigation
  //inputs into selector;
  //await page.$eval('#text-input-what', el => el,value = 'Cyber Intern');
  await page.type('#text-input-what', 'IT intern');
  console.log("inputing\n");
  await page.click('#whatWhere > form > div.icl-WhatWhere-buttonWrapper > button');
  await page.waitForSelector('#sja1');
  await page.screenshot({path: 'screenshots/indeed.png'});
  //Write pdf
  await page.pdf(options);
  browser.close();
};

scrape().then((value) => {

});
// async function run() {
//   const browser = await puppeteer.launch({args: ['--no-sandbox', '--disable-setuid-sandbox']});
//   const page = await browser.newPage();
  
//   await page.goto(address);
//   //await page.section()
//   await page.screenshot({path: 'screenshots/github.png'});
//   console.log(address);
//   browser.close();
// }

// run();