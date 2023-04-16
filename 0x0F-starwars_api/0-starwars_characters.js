#!/usr/bin/node
// a script that prints all characters of a Star Wars movie.

const request = require('request');
const movieId = process.argv[2];

request(`https://swapi-api.hbtn.io/api/films/${movieId}/`, function (error, response, body) {
  if (error) {
    console.log(`Error: Could not retrieve movie details for Movie ID ${movieId}`);
    return;
  }

  if (response.statusCode !== 200) {
    console.log(`Error: Could not retrieve movie details for Movie ID ${movieId}`);
    return;
  }

  const movie = JSON.parse(body);
  const characterUrls = movie.characters;

  characterUrls.forEach(function (characterUrl) {
    request(characterUrl, function (error, response, body) {
      if (error) {
        console.log(`Error: Could not retrieve character details for URL ${characterUrl}`);
        return;
      }

      if (response.statusCode !== 200) {
        console.log(`Error: Could not retrieve character details for URL ${characterUrl}`);
        return;
      }

      const character = JSON.parse(body);
      console.log(character.name);
    });
  });
});