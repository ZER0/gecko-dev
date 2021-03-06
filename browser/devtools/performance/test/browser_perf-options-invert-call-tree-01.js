/* Any copyright is dedicated to the Public Domain.
   http://creativecommons.org/publicdomain/zero/1.0/ */

const INVERT_PREF = "devtools.performance.ui.invert-call-tree";

/**
 * Tests that the js call tree view is re-rendered after the
 * "invert-call-tree" pref is changed.
 */
function spawnTest () {
  let { panel } = yield initPerformance(SIMPLE_URL);
  let { EVENTS, DetailsView, JsCallTreeView } = panel.panelWin;

  Services.prefs.setBoolPref(INVERT_PREF, true);

  DetailsView.selectView("js-calltree");
  ok(DetailsView.isViewSelected(JsCallTreeView), "The call tree is now selected.");

  yield startRecording(panel);
  yield busyWait(100);

  let rendered = once(JsCallTreeView, EVENTS.JS_CALL_TREE_RENDERED);
  yield stopRecording(panel);
  yield rendered;

  rendered = once(JsCallTreeView, EVENTS.JS_CALL_TREE_RENDERED);
  Services.prefs.setBoolPref(INVERT_PREF, false);
  yield rendered;

  ok(true, "JsCallTreeView rerendered when toggling invert-call-tree.");

  rendered = once(JsCallTreeView, EVENTS.JS_CALL_TREE_RENDERED);
  Services.prefs.setBoolPref(INVERT_PREF, true);
  yield rendered;

  ok(true, "JsCallTreeView rerendered when toggling back invert-call-tree.");

  yield teardown(panel);
  finish();
}
