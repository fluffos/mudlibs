// Decompression worker for zip-loader.js. A large lib's zip can hold tens
// of thousands of individually-DEFLATEd entries (e.g. one real lib: ~60K
// files) -- decompressing them on the main thread, even with many
// concurrent DecompressionStream calls in flight, is bounded by that one
// thread's own per-call JS overhead (Blob/stream construction, promise
// scheduling), not by how many CPU cores the visitor's device has. Workers
// give genuine multi-core parallelism: zip-loader.js spawns a small pool of
// these, each independently decompressing whatever entry it's handed next.
// This file does ONLY decompression -- it never touches Module.FS (workers
// can't reach the main thread's Emscripten Module at all), so
// zip-loader.js still does every filesystem write itself, on the main
// thread, after collecting a worker's result.
self.onmessage = async (ev) => {
  const { id, raw } = ev.data;
  try {
    const ds = new DecompressionStream('deflate-raw');
    const stream = new Blob([raw]).stream().pipeThrough(ds);
    const data = new Uint8Array(await new Response(stream).arrayBuffer());
    self.postMessage({ id, ok: true, data }, [data.buffer]);
  } catch (e) {
    self.postMessage({ id, ok: false, error: String((e && e.message) || e) });
  }
};
