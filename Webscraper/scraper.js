const puppeteer = require('puppeteer');
const address = 'https://www.indeed.com/';

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
  await page.type('#text-input-what', 'Cyber Intern');
  console.log("inputing\n");
  await page.click('#whatWhere > form > div.icl-WhatWhere-buttonWrapper > button');
  await page.screenshot({path: 'screenshots/indeed.png'});
  browser.close();
};

scrape().then((value) => {
	console.log(value);
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