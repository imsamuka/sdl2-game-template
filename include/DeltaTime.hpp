#pragma once

struct DeltaTime
{
  DeltaTime(float time = 0.0f) : deltaTime(time) {}

  operator float() const { return deltaTime; }

  [[nodiscard]] float GetSeconds() const { return deltaTime; }
  [[nodiscard]] float GetMilliseconds() const { return deltaTime * 1000.0f; }
private:
  float deltaTime;
};